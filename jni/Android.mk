LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := test-aslr
LOCAL_SRC_FILES := test-aslr.c

include $(BUILD_EXECUTABLE)
