# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Coverage flags (optional)
COVFLAGS = --coverage -O0 

# Source files
SRCS = TestingMain.cpp \
       InteractionMediator.cpp \
       InventoryMediator.cpp \
	   Blooming.cpp \
	   BonsaiTree.cpp \
	   BulkDiscount.cpp \
	   BreadthFirstIterator.cpp \
	   Colleague.cpp \
	   Command.cpp \
	   Customer.cpp \
	   FlowerFactory.cpp \
	   GreenHouseStaff.cpp \
	   Jacka.cpp \
	   Mangrove.cpp \
	   Mature.cpp \
	   PeaceLily.cpp \
	   PlantType.cpp \
	   Rose.cpp \
	   SeasonalDiscount.cpp \
	   ShoppingCart.cpp \
	   Seedling.cpp \
	   TreeFactory.cpp \
	   WaterLily.cpp \
	   Withering.cpp \
	   WitheringDiscount.cpp 

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = nursery

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

# Coverage target
coverage: clean
	$(CXX) $(CXXFLAGS) $(COVFLAGS) $(SRCS) -o $(TARGET)
	./$(TARGET)
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory=out

# Clean up object files and executables
clean:
	rm -f $(OBJS) $(TARGET) *.gcda *.gcno *.gcov coverage.info
	rm -rf out

# Memory check (optional)
valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

# Phony targets
.PHONY: all clean coverage valgrind
