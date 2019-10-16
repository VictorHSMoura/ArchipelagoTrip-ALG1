CC := g++
CFLAGS := -g -Wall

TARGET := tp2
SRCDIR := src
OBJDIR := obj

SOURCES := $(shell find $(SRCDIR) -type f -name *.cpp)

OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

$(TARGET): $(OBJECTS)
	@mkdir -p $(@D) # Criar diretório caso necessário
	@$(CC) $^ -o $@

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@mkdir -p $(@D) # Criar diretório caso necessário
	@$(CC) $(CFLAGS) -c $^ -o $@

.PHONY: run clean
run: $(TARGET)

clean:
	@rm -rf $(TARGET) $(OBJDIR)