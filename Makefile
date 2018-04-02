vpath %.c  src
vpath %.h  include


OBJ_DIR = obj
SRC_DIR = src

COMPILE.cpp = $(CXX) $(CFLAGS) $(INCLUDES) $(CXXFLAGS) $(TARGET_ARCH) -c
CXXFLAGS += -I include
CXXFLAGS += -I C:\Lib\eigen_3_3_4
CXXFLAGS += -g

$(info COMPILE.cpp="${COMPILE.cpp}")
$(info CXXFLAGS="${CXXFLAGS}")
AWK = awk
SORT = sort
PR = pr 
START = start

SRC_FILES := $(wildcard ${SRC_DIR}/*.cpp)
$(info sources="${SRC_FILES}")
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
$(info objets="${OBJ_FILES}")
$(info CXXFLAGS="${CXXFLAGS}")

LoLo : ${OBJ_FILES}
#	g++ $^ -o $@
	g++ -o bin/$@ $^
	

#%.o: %.cpp
#	gcc -c $(CXXFLAGS) $<
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(CXXFLAGS) -c  $< -o $@

clean:
	del $(OBJ_DIR)\*.d  $(OBJ_DIR)\*.o bin\*.exe
#	rm -f $(OBJS) $(TARGET)

clean_linux:
	rm -f $(OBJ_DIR)\*.d  $(OBJ_DIR)\*.o bin\*.exe
#	rm -f $(OBJS) $(TARGET)
 


 
.PHONY: help LoLo clean all

all: LoLo

# help - The default goal
help:
	$(MAKE) --print-data-base --question | \
	$(AWK) '/^[^.%][-A-Za-z0-9_]*:/ \
	{ print substr($$1, 1, length($$1)-1) }' | $(SORT) | $(PR) --omit-pagination --width=80 --columns=4

CXXFLAGS += -MMD
-include $(OBJ_FILES:.o=.d)

