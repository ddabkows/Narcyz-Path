# Makefile for G11 L-type : how to use it
#
# Place source code in src/ (can contain subfolders)
# Build will place object files into corresponding folder structure
# in build/
# Use 'gmake' to specifiy use of GNU make rather than system default
# Use 'gmake init' target to setup githook for astyle
# Can use 'gmake -j number_of_jobs' to make targets in parallel (refer to make docs for help)
#--------------------------------------------------------------------------------

# Set project directory one level above of Makefile directory.
PROJDIR   := $(strip $(realpath $(CURDIR)/..))
SOURCEDIR := $(strip $(PROJDIR)/src)
BUILDDIR  := $(strip $(PROJDIR)/build/build)

#================================================================================
# CLIENT
C_SRC_DIR        := $(SOURCEDIR)/Client
C_BUILD_DIR      := $(BUILDDIR)/Client
C_SOURCES        := $(wildcard $(C_SRC_DIR)/*.cpp)
C_OBJS           := $(patsubst $(C_SRC_DIR)/%,$(C_BUILD_DIR)/%,$(C_SOURCES:.cpp=.o))
C_DEPS           := $(C_OBJS:.o=.d)
# Names of the final executables
CLIENT := NarcyzPath

#================================================================================

# Client parts                       : GUI --------------------------------------
GUI_SRC_DIR    := $(SOURCEDIR)/GUI
GUI_BUILD_DIR  := $(BUILDDIR)/GUI
GUI_SOURCES    := $(wildcard $(GUI_SRC_DIR)/*.cpp)
GUI_OBJS       := $(patsubst $(GUI_SRC_DIR)/%,$(GUI_BUILD_DIR)/%,$(GUI_SOURCES:.cpp=.o))
GUI_DEPS       := $(GUI_OBJS:.o=.d)

# Client parts                      : Game --------------------------------------
G_SRC_DIR    := $(SOURCEDIR)/Game
G_BUILD_DIR  := $(BUILDDIR)/Game
G_SOURCES    := $(wildcard $(G_SRC_DIR)/*.cpp)
G_OBJS       := $(patsubst $(G_SRC_DIR)/%,$(G_BUILD_DIR)/%,$(G_SOURCES:.cpp=.o))
G_DEPS       := $(G_OBJS:.o=.d)

# FLAGS -------------------------------------------------------------------------
FLAGS_ENABLED := TRUE
CORE_FLAGS    := TRUE

# Enable debug flags
DEBUG_ENABLED := TRUE

CC    := g++

FLAGS := -std=c++17 -masm=intel
ifeq ($(CORE_FLAGS), TRUE)
	FLAGS += -Wall -Wextra
endif
ifeq ($(FLAGS_ENABLED), TRUE)
	FLAGS += -fconcepts -pthread -fopenacc -fopenmp  -Wpedantic
	FLAGS += -Wconversion -Winline -Wsign-conversion -Weffc++ -Wstrict-null-sentinel -Wold-style-cast -Wnoexcept
	FLAGS += -Wctor-dtor-privacy -Woverloaded-virtual -Wsign-promo -Wzero-as-null-pointer-constant -Wsuggest-final-types
	FLAGS += -Wsuggest-final-methods -Wsuggest-override
endif
ifeq ($(DEBUG_ENABLED), TRUE)
	FLAGS += -ggdb3		# Debugging symbols, by default this is not a production build
	# FALGS += fsanitize-threads
endif

# LIBS --------------------------------------------------------------------------
CLIENT_LIBS := 
GAME_LIBS   := 
GUI_LIBS    := -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system 

# UTILITIES ---------------------------------------------------------------------
RM        := rm -f
RMDIR     := rm -rf
MKDIR     := mkdir -p
CLEAR:
	clear
#--------------------------------------------------------------------------------

.PHONY: all clean directories init mrproper print_help

all: client 
client: GUI_directories G_directories C_directories $(CLIENT)
game: G_directories 
gui: GUI_directories 

GUI_directories:
	$(MKDIR) $(GUI_BUILD_DIR)
G_directories:
	$(MKDIR) $(G_BUILD_DIR)
C_directories:
	$(MKDIR) $(C_BUILD_DIR)

# Remove all objects, dependencies generated during build
clean_client:
	$(RMDIR) $(C_BUILD_DIR)
	@echo Cleaning done !
clean_game:
	$(RMDIR) $(G_BUILD_DIR)
	@echo Cleaning done !
clean_gui:
	$(RMDIR) $(GUI_BUILD_DIR)
	@echo Cleaning done !

# Clean + remove executable files
mrproper_client: clean_client clean_game clean_gui
	$(RM) $(CLIENT)
mrproper_game: clean_game

mrproper_gui: clean_gui

mrproper: mrproper_client

init:
	git config core.hooksPath .githooks		# Add .githooks

#================================================================================
DEPS := -MMD
# Compilation rules for object files
$(C_BUILD_DIR)/%.o : $(C_SRC_DIR)/%.cpp
	$(CC) $(FLAGS) $(DEPS) -c -o $@ $< $(CLIENT_LIBS)

$(GUI_BUILD_DIR)/%.o : $(GUI_SRC_DIR)/%.cpp
	$(CC) $(FLAGS) $(DEPS) -c -o $@ $< $(GUI_LIBS)

$(G_BUILD_DIR)/%.o : $(G_SRC_DIR)/%.cpp
	$(CC) $(FLAGS) $(DEPS) -c -o $@ $< $(GAME_LIBS)

# CLIENT ------------------------------------------------------------------------

$(CLIENT): LIBS := $(CLIENT_LIBS) $(G_LIBS) $(GUI_LIBS)
$(CLIENT): INCLUDES := $(C_INCLUDES) $(GUI_INCLUDES) $(G_INCLUDES)
$(CLIENT): $(C_OBJS) $(GUI_OBJS) $(G_OBJS)
	@echo Linking $@
	$(CC) $^ -o $@ $(LIBS)

#================================================================================
# Include dependencies
-include $(C_DEPS)
-include $(GUI_DEPS)
-include $(G_DEPS)

#================================================================================
# Print all variables in makefile except those listed here (blacklist print)
PRINT_IGNORE := PRINT_IGNORE FLAGS
PRINT_IGNORE += .DEFAULT_GOAL .SHELLSTATUS VPATH #LIBS
#PRINT_IGNORE += C_DIRS C_SOURCEDIRS  C_OBJS
#PRINT_IGNORE += S_DIRS S_SOURCEDIRS  S_OBJS
#PRINT_IGNORE += CM_DIRS CM_SOURCEDIRS CM_OBJS
PRINT_IGNORE += MAKEFILE_LIST MAKEFLAGS GNUMAKEFLAGS
PRINT_IGNORE += RM RMDIR MKDIR SHELL

print_help: $(CLEAR)
	@echo -----------------------------------------------------------------------
	@$(foreach V,$(sort $(.VARIABLES)), \
			$(if $(and $(filter-out environment% default automatic, $(origin $V)), \
				$(filter-out $(PRINT_IGNORE), $V)), $(info $V = $($V))))

