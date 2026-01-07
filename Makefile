# Настройки
CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGET = main
BUILD_DIR = builds

# Поиск всех .cpp файлов во всех подпапках
SRCS = $(shell find . -name "*.cpp")
# Превращаем пути .cpp в пути к объектным файлам .o в папке builds
OBJS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Правило по умолчанию (просто сборка)
all: $(BUILD_DIR)/$(TARGET)

# Ссылка (Linking) - собирает исполняемый файл из объектных
$(BUILD_DIR)/$(TARGET): $(OBJS)
	@mkdir -p $(dir $@)
	$(CXX) $(OBJS) -o $@

# Компиляция (Compiling) - создает .o файлы из .cpp
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Команда для запуска (без принудительной пересборки)
run:
	@if [ -f $(BUILD_DIR)/$(TARGET) ]; then \
		./$(BUILD_DIR)/$(TARGET); \
	else \
		echo "Файл не найден. Сначала выполните 'make'"; \
	fi

# Собрать и сразу запустить
br: all run

# Очистка папки сборки
clean:
	rm -rf $(BUILD_DIR)
