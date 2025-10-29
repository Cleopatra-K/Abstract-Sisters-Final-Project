#Absatract Sisters Final Project Makefile 
# =======================================================================
# COMPILER AND FLAGS CONFIGURATION
# =======================================================================

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -g -Werror

# AddressSanitizer flags
ASANFLAGS = -fsanitize=address -fno-omit-frame-pointer -std=c++11 -Wall -Wextra -pedantic -g -Werror

# Coverage flags
COV_FLAGS = -fprofile-arcs -ftest-coverage

# Executable names
MAIN_TARGET = plant_system
ASAN_TARGET = plant_system_asan
COV_TARGET = plant_system_cov

# =======================================================================
# SOURCE AND OBJECT FILE DEFINITIONS
# =======================================================================

# List of all C++ source files required for the Plant Factory System
# REMOVED: Outdoor.cpp Indoor.cpp Aquatic.cpp (abstract classes)
SRCS = TestingMain.cpp FlowerFactory.cpp TreeFactory.cpp \
	Rose.cpp Jacka.cpp PeaceLily.cpp BonsaiTree.cpp WaterLily.cpp Mangrove.cpp \
	PlantType.cpp \
	ColourImplementation.cpp Red.cpp Green.cpp Yellow.cpp \
	Aquatic.cpp Outdoor.cpp Indoor.cpp \
    BulkDiscount.cpp Customer.cpp SeasonalDiscount.cpp ShoppingCart.cpp WitheringDiscount.cpp \
	GreenHouse.cpp GreenHouseIterator.cpp \
	Colleague.cpp  


# Object files
OBJS = $(SRCS:.cpp=.o)
ASAN_OBJS = $(SRCS:.cpp=.asan.o)
COV_OBJS = $(SRCS:.cpp=.cov.o)

# Header files
HEADERS = PlantType.h PlantFactory.h FlowerFactory.h TreeFactory.h \
	Outdoor.h Indoor.h Aquatic.h \
	Rose.h Jacka.h PeaceLily.h BonsaiTree.h WaterLily.h Mangrove.h\
	ColourImplementation.h Red.h Green.h Yellow.h \
	BulkDiscount.h Customer.h SeasonalDiscount.h ShoppingCart.h WitheringDiscount.h \
	GreenHouse.h GreenHouseIterator.h \
	Colleague.h Mediator.h  

# =======================================================================
# BUILD TARGETS
# =======================================================================

all: $(MAIN_TARGET)

$(MAIN_TARGET): $(OBJS)
	@echo "Building Plant Factory System (C++11, -Wall, -Wextra, -Werror)..."
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "Build completed successfully!"

$(ASAN_TARGET): $(ASAN_OBJS)
	@echo "Building with AddressSanitizer..."
	$(CXX) $(ASANFLAGS) -o $@ $^
	@echo "ASan build completed successfully!"

$(COV_TARGET): $(COV_OBJS)
	@echo "Building with Coverage instrumentation..."
	$(CXX) $(CXXFLAGS) $(COV_FLAGS) -o $@ $^
	@echo "Coverage build completed successfully!"

# Explicit rule for .asan.o (macOS fix)
%.asan.o: %.cpp
	@echo "Compiling $< with ASan..."
	$(CXX) $(ASANFLAGS) -c $< -o $@

# Explicit rule for coverage .cov.o
%.cov.o: %.cpp $(HEADERS)
	@echo "Compiling $< with coverage..."
	$(CXX) $(CXXFLAGS) $(COV_FLAGS) -c $< -o $@

# Explicit rule for normal .o
%.o: %.cpp $(HEADERS)
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# =======================================================================
# TESTING AND ANALYSIS TARGETS
# =======================================================================

.PHONY: test valgrind coverage clean zip help

# --- Run Tests ---
run: $(MAIN_TARGET)
	@echo "--- Running Plant Factory System Tests ---"
	./$(MAIN_TARGET)

# --- AddressSanitizer ---
asan: $(ASAN_TARGET)
	@echo "--- Running tests with AddressSanitizer ---"
	./$(ASAN_TARGET)

# --- Valgrind Memory Check ---
valgrind: $(MAIN_TARGET)
	@echo "--- Running Valgrind Memory Check ---"
	valgrind --leak-check=full \
			--show-leak-kinds=all \
			--track-origins=yes \
			./$(MAIN_TARGET)

# --- Code Coverage ---
coverage: $(COV_TARGET)
	@echo "--- Running tests to generate coverage data ---"
	./$(COV_TARGET)
	@echo "--- Generating Coverage Report via gcov ---"
	gcov $(SRCS)
	@echo "Coverage files (.gcov) generated."
	@if command -v lcov > /dev/null; then \
		lcov --capture --directory . --output-file coverage.info; \
		genhtml coverage.info --output-directory coverage_html; \
		echo "HTML coverage report generated in coverage_html/index.html"; \
	else \
		echo "lcov not found. Install it for HTML coverage reports"; \
	fi

# --- GDB Debugging ---
gdb: $(MAIN_TARGET)
	@echo "--- Starting GDB Debug Session ---"
	gdb ./$(MAIN_TARGET)

# =======================================================================
# CLEANUP AND PACKAGING
# =======================================================================

# --- Clean ---
clean:
	@echo "Cleaning build artifacts..."
	rm -f $(OBJS) $(ASAN_OBJS) $(COV_OBJS)
	rm -f $(MAIN_TARGET) $(ASAN_TARGET) $(COV_TARGET)
	rm -f *.gcno *.gcda coverage.info *.gcov *.asan.o
	rm -rf coverage_html

# --- Create submission package ---
zip: clean
	@echo "Creating submission package abstratsisters.zip..."
	zip -r abstratsisters.zip *.cpp *.h Makefile README* *.md 2>/dev/null || true
	@echo "Created abstratsisters.zip"
	@ls -lh abstratsisters.zip

# --- Helper ---
help:
	@echo "Available targets:"
	@echo "  all       - Build plant factory system"
	@echo "  test      - Run tests"
	@echo "  asan      - Build and run with AddressSanitizer"
	@echo "  valgrind  - Run with Valgrind memory checker"
	@echo "  coverage  - Build and generate coverage report"
	@echo "  gdb       - Debug with GDB"
	@echo "  clean     - Clean build artifacts"
	@echo "  zip       - Create submission package u23547121.zip"

.PHONY: all test asan valgrind coverage gdb clean zip help