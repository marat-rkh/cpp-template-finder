source 'settings.sh'

mkdir -p $BUILD_DIR
pushd $BUILD_DIR > /dev/null
cmake -D LLVM_PATH=$1 ..
make
popd > /dev/null
