import os
from typing import Iterable

# Tokens
META_SWITCH = 'CFG_META_SWITCH'
META_DELAY = 'CFG_META_DELAY'
META_BURST = 'CFG_META_BURST'

COMPRESS_SUFFIX = "_cmpr"

MIN_ZEROS = 4
MIN_SEQ = 2


def main():
    value = []
    register = []
    page = []
    book = []

    # Find all header files that begin with "eco_"
    filenames = []
    script_dir = os.path.abspath(os.path.dirname(__file__))
    print(script_dir)
    for filename in os.listdir(script_dir):
        if filename.startswith("eco_58") and filename.endswith(".h") and COMPRESS_SUFFIX not in filename:
            filenames.append(filename)

    # filenames = ["eco_5805_test.h"]
    for filename in filenames:
        with open(filename, "r") as file:
            output_lines = []
            input_lines = iter(line.strip("\n") for line in file.readlines())
            try:
                while True:
                    line = next(input_lines)
                    output_lines.append(line)

                    if "const" in line:
                        examine(input_lines, output_lines)
            except StopIteration:
                pass
        filename_pre, _ = filename.split(".", 1)
        with open(filename_pre + COMPRESS_SUFFIX + ".h", "w") as file:
            file.write("\n".join(output_lines))
        print(filename)
        # exit(0)


def examine(input_lines: Iterable, output_lines: list):
    pairs = []
    while True:
        line = next(input_lines)
        if "{" in line and "}" in line:
            data = line.split("{")[-1]
            data = data.split("}")[0]
            data = [value.strip() if "META" in value else int(value, 16 if "0x" in value else 10) for value in
                    data.split(",")]
            pairs.append(data)

        elif ";" in line:
            for data in unroll(pairs):
                if isinstance(data[0], str):
                    text = f"\t{{ {data[0]}, {data[1]} }},"
                else:
                    text = f"\t{{ 0x{data[0]:02x}, 0x{data[1]:02x} }},"
                output_lines.append(text)
            output_lines.append(line)
            return

        elif line:
            output_lines.append(line.strip("\n"))


def unroll(data_list: list) -> list:
    data_input = iter(data_list)
    data_output = []
    try:
        while True:
            data = next(data_input)
            if data[0] == META_BURST:
                i = data[1] - 2  # First value is register
                register, value = next(data_input)
                data_output.append([register, value])
                register += 1
                while True:
                    data = next(data_input)
                    data_output.append([register, data[0]])
                    register += 1
                    i -= 1
                    if not i:
                        break
                    data_output.append([register, data[1]])
                    register += 1
                    i -= 1
                    if not i:
                        break
            else:
                data_output.append(data)

    except StopIteration:
        pass

    seq = 0
    seq_list = []
    zeros = 0
    zeros_list = []

    prev_reg = -99
    for (reg, value) in reversed(data_output):
        if isinstance(reg, int) and reg == prev_reg - 1:
            seq += 1
            if value == 0:
                zeros += 1
            else:
                zeros = 0
        else:
            zeros = 0
            seq = 0
        prev_reg = reg if isinstance(reg, int) else -99
        seq_list.append(seq)
        zeros_list.append(zeros)
    seq_list.reverse()
    zeros_list.reverse()
    [print(z) for z in zip(data_output, seq_list, zeros_list)]

    data_compressed = []
    data = zip(data_output, seq_list, zeros_list)
    try:
        while True:
            (reg, value), seq, zeros = next(data)
            if zeros > MIN_ZEROS:
                data_compressed.append([reg, value])
                data_compressed.append([META_SWITCH, zeros])
                for _ in range(zeros):
                    next(data)

            else:
                data_compressed.append([reg, value])
    except StopIteration:
        pass

    seq = 0
    seq_list = []
    zeros = 0
    zeros_list = []
    prev_reg = -99
    for (reg, value) in reversed(data_compressed):
        if isinstance(reg, int) and reg == prev_reg - 1:
            seq += 1
            if value == 0:
                zeros += 1
            else:
                zeros = 0
        else:
            zeros = 0
            seq = 0
        prev_reg = reg if isinstance(reg, int) else -99
        seq_list.append(seq)
        zeros_list.append(zeros)
    seq_list.reverse()
    zeros_list.reverse()
    [print(z) for z in zip(data_compressed, seq_list, zeros_list)]
    data = zip(data_compressed, seq_list, zeros_list)

    data_output = []
    try:
        while True:
            (reg, value), seq, zeros = next(data)
            if seq > MIN_SEQ:
                data_output.append(
                    [META_BURST, seq + 2])  # +2 because first repeat is missed and also need to write register
                data_output.append([reg, value])
                while seq:
                    if seq > 1:
                        (_, value_1), _, _ = next(data)
                        (_, value_2), _, _ = next(data)
                        data_output.append([value_1, value_2])
                        seq -= 2
                    else:
                        (_, value_1), _, _ = next(data)
                        data_output.append([value_1, 0])
                        seq -= 1
            else:
                data_output.append([reg, value])

    except StopIteration:
        pass

    return (data_output)


if __name__ == "__main__":
    main()
