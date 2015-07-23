include vendor/Spark-Core-IRremote/1.0.0/lib.mk

SRC_FILES = ac_control.ino
COMPILE_FILES = $(SRC_FILES) $(INCLUDE_FILES)

flash: $(SRC_FILES)
	particle flash ac_control $(COMPILE_FILES)

compile: $(SRC_FILES)
	particle compile photon $(COMPILE_FILES)

default: flash
