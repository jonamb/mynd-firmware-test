FROM frolvlad/alpine-glibc:glibc-2.28

RUN apk --update --no-cache upgrade && \
    apk --update --no-cache add make cmake python2 python3 py-pip protobuf git git-lfs ninja openssl && \
    apk --update --no-cache add --virtual build-dependencies w3m wget curl ca-certificates && \
    wget --no-check-certificate -O /tmp/gcc-arm-none-eabi.tar.bz2 https://developer.arm.com/-/media/Files/downloads/gnu/13.2.rel1/binrel/arm-gnu-toolchain-13.2.rel1-x86_64-arm-none-eabi.tar.bz2 && \
    tar xf /tmp/gcc-arm-none-eabi.tar.bz2 --strip-components=1 -C /usr/local && \
    rm -rf /tmp/gcc-arm-none-eabi.tar.bz2 && \
    rm -rf /usr/local/share/doc && \
    curl -fL https://releases.jfrog.io/artifactory/jfrog-cli/v2-jf/2.49.1/scripts/install-cli.sh | sh && \
    apk del build-dependencies
RUN pip3 install --no-cache-dir --upgrade pip && \
    pip3 install --no-cache-dir protobuf && \
    pip3 install --no-cache-dir crcmod && \
    pip3 install --no-cache-dir intelhex
