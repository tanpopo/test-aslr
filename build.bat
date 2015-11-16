SET target_abi=armeabi-v7a
SET out_filename="test-aslr"
SET out_filepath="libs\"%target_abi%%out_filename%
SET dest_path="/mnt/shell/emulated/0/"

echo "out_filepath="%out_filepath%
del /Q %out_filepath%
ndk-build -B NDK_LOG=1

IF EXIST %out_filepath% (
adb push %out_filepath$ %dest_path%"/"%out_filename%
) ELSE (
echo "output_file not exist"
)

