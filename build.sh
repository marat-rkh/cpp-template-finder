source 'settings.sh'

mkdir -p $BUILD_DIR
pushd $BUILD_DIR > /dev/null
cmake -D LLVM_SRC_PATH=$1 -D LLVM_BUILD_PATH=$2 ..
make
popd > /dev/null
