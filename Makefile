CXX = g++
CXXFLAGS = -std=c++20 -static -Wall -Wextra
TARGET = bin/ironsql
LOG = log/compile.log

SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

INCLUDE_DIRS = \
	-I$(SRC_DIR)/include \
	-I$(SRC_DIR)/release \
	-I$(SRC_DIR)/kernel \
	-I$(SRC_DIR)/test \
	-I$(SRC_DIR)/logsystem \
	-I$(SRC_DIR)/.windows \
	-I$(SRC_DIR)/.linux \
	-I$(SRC_DIR)/stdiostreams \
	-I$(SRC_DIR)/.include \
	-I$(SRC_DIR)/loads \
	-I$(SRC_DIR)/.path \
	-I$(SRC_DIR)/.ironfsystem

SOURCE_FILES = \
	$(SRC_DIR)/iron_main.cpp \
	$(SRC_DIR)/test/iron_test.cpp \
	$(SRC_DIR)/library/iron_server.cpp \
	$(SRC_DIR)/library/iron_server_settings.cpp \
	$(SRC_DIR)/library/iron_handle.cpp \
	$(SRC_DIR)/library/iron_status.cpp \
	$(SRC_DIR)/library/iron_fmtout.cpp \
	$(SRC_DIR)/library/iron_parser.cpp \
	$(SRC_DIR)/library/iron_help.cpp \
	$(SRC_DIR)/library/iron_pathfs.cpp \
	$(SRC_DIR)/release/iron_object.cpp \
	$(SRC_DIR)/kernel/iron_proces.cpp \
	$(SRC_DIR)/kernel/iron_keywds.cpp \
	$(SRC_DIR)/kernel/iron_verify.cpp \
	$(SRC_DIR)/kernel/iron_syntax.cpp \
	$(SRC_DIR)/logsystem/iron_logsystem.cpp \
	$(SRC_DIR)/stdiostreams/iron_stdout.cpp \
	$(SRC_DIR)/loads/iron_load_settings_conf.cpp \
	$(SRC_DIR)/.path/iron_path_manage.cpp \
	$(SRC_DIR)/.path/iron_path_windows.cpp \
	$(SRC_DIR)/.path/iron_path_linux.cpp \
	$(SRC_DIR)/.path/iron_path_init.cpp \
	$(SRC_DIR)/.ironfsystem/iron_file_system.cpp \
	$(SRC_DIR)/.linux/iron_linux_systempath.cpp \
	$(SRC_DIR)/.windows/iron_windows_systempath.cpp

OBJECT_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCE_FILES))
RESOURCE_FILE = $(BUILD_DIR)/resource.o
ICON_PATH = img/IronSQL_1.ico

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJECT_FILES) $(RESOURCE_FILE)
	@echo "Linking..."
	@mkdir -p $(BIN_DIR)
	@$(CXX) $(CXXFLAGS) $(OBJECT_FILES) $(RESOURCE_FILE) -o $(TARGET) 2>>$(LOG)
	@if [ $$? -eq 0 ]; then \
		echo "Link successful!"; \
		echo "Copying config files..."; \
		rm -rf $(BIN_DIR)/.config; \
		cp -rpf $(SRC_DIR)/.config $(BIN_DIR)/.config; \
		echo "Build complete! Binary: $(TARGET)"; \
	else \
		echo "Link failed! Check $(LOG) for details."; \
		exit 1; \
	fi

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "Compiling $<..."
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -c $< -o $@ 2>>$(LOG)
	@if [ $$? -ne 0 ]; then \
		echo "Compilation failed for $<! Check $(LOG) for details."; \
		exit 1; \
	fi

$(RESOURCE_FILE): $(ICON_PATH)
	@echo "Creating resource file..."
	@mkdir -p $(BUILD_DIR)
	@echo "1 ICON \"$(ICON_PATH)\"" > $(SRC_DIR)/resource.rc
	@windres $(SRC_DIR)/resource.rc -o $(RESOURCE_FILE)
	@rm -f $(SRC_DIR)/resource.rc

clean:
	@echo "Cleaning build files..."
	@rm -rf $(BUILD_DIR)
	@rm -f $(TARGET)
	@rm -f $(LOG)
	@echo "Clean complete!"

run: $(TARGET)
	@echo "Running $(TARGET)..."
	@$(TARGET)

help:
	@echo "IronSQL Makefile"
	@echo "================"
	@echo "Available targets:"
	@echo "  all    - Build the project (default)"
	@echo "  clean  - Remove build files"
	@echo "  run    - Build and run the executable"
	@echo "  help   - Show this help message"
	@echo ""
	@echo "Compiler: $(CXX)"
	@echo "Target:   $(TARGET)"
