NAME = test.out
RENDU_PATH = ../..
FRAMEWORK_PATH = ../../../moulitest/testframework/v3
CC_LIBS = -ltowel -L $(RENDU_PATH)/libs/libtowel -I $(RENDU_PATH)/libs/libtowel/includes
RENDU_SOURCE = $(RENDU_PATH)/srcs/**/*.c
RENDU_MAKE_ARG =
