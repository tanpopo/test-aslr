LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

#http://developer.android.com/intl/ja/ndk/guides/application_mk.html
APP_PLATFORM := android-16
APP_ABI := armeabi armeabi-v7a

LOCAL_MODULE    := test-aslr
LOCAL_SRC_FILES := test-aslr.c

include $(BUILD_EXECUTABLE)
