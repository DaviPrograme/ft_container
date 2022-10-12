NAME := ft_container
MAIN_VECTOR_STD := mainVectorSTD
MAIN_VECTOR_FT := mainVectorFT
MAIN_STACK_STD := mainStackSTD
MAIN_STACK_FT := mainStackFT
MAIN_MAP_STD := mainMapSTD
MAIN_MAP_FT := mainMapFT

PATH_VECTOR_TESTS = ./tests/vector/src/
VECTOR_FILES = vectorBenchmark.cpp pushBackTests.cpp vectorUnitTests.cpp \
				popBackTests.cpp sizeTests.cpp capacityTests.cpp emptyTests.cpp \
				reserveTests.cpp clearTests.cpp maxSizeTests.cpp resizeTests.cpp \
				swapTests.cpp eraseTests.cpp insertTests.cpp assignTests.cpp atTests.cpp \
				backTests.cpp frontTests.cpp beginTests.cpp endTests.cpp rBeginTests.cpp \
				rEndTests.cpp constructorDefaultTests.cpp constructorFillTests.cpp \
				constructorRangeTests.cpp dataTests.cpp
PATH_VECTOR_FILES = $(addprefix $(PATH_VECTOR_TESTS), $(VECTOR_FILES))

PATH_STACK_TESTS = ./tests/stack/src/
STACK_FILES = stackBenchmark.cpp pushTests.cpp stackUnitTests.cpp \
				popTests.cpp sizeTests.cpp emptyTests.cpp topTests.cpp \
				constructorDefaultTests.cpp
PATH_STACK_FILES = $(addprefix $(PATH_STACK_TESTS), $(STACK_FILES))


PATH_MAP_TESTS = ./tests/map/src/
MAP_FILES = mapUnitTests.cpp mapBenchmark.cpp insertTests.cpp mapAuxTests.cpp sizeTests.cpp \
			beginTests.cpp endTests.cpp rendTests.cpp rbeginTests.cpp emptyTests.cpp maxSizeTests.cpp \
			atTests.cpp operator[]Tests.cpp clearTests.cpp eraseTests.cpp swapTests.cpp countTests.cpp \
			findTests.cpp lowerBoundTests.cpp upperBoundTests.cpp equalRangeTests.cpp \
			constructorDefaultTests.cpp constructorCopyTests.cpp constructorRangeTests.cpp \
			valueCompTests.cpp getAllocatorTests.cpp keyCompTests.cpp
PATH_MAP_FILES = $(addprefix $(PATH_MAP_TESTS), $(MAP_FILES))


PATH_AUX_TESTS =./tests/aux/
AUX_FILES = auxTests.cpp
PATH_AUX_FILES = $(addprefix $(PATH_AUX_TESTS), $(AUX_FILES))

all: $(NAME)

$(NAME): 
	c++ -Wall -Wextra -Werror -g main.cpp $(PATH_VECTOR_FILES) $(PATH_STACK_FILES) $(PATH_MAP_FILES) $(PATH_AUX_FILES) -std=c++98 -o $(NAME)
	c++ -Wall -Wextra -Werror -g ./tests/stack/mainFT.cpp -std=c++98 -o $(MAIN_STACK_FT)
	c++ -Wall -Wextra -Werror -g ./tests/stack/mainSTD.cpp -std=c++98 -o $(MAIN_STACK_STD) 
	c++ -Wall -Wextra -Werror -g ./tests/vector/mainFT.cpp -std=c++98 -o $(MAIN_VECTOR_FT)
	c++ -Wall -Wextra -Werror -g ./tests/vector/mainSTD.cpp -std=c++98 -o $(MAIN_VECTOR_STD) 
	c++ -Wall -Wextra -Werror -g ./tests/map/mainSTD.cpp -std=c++98 -o $(MAIN_MAP_STD)
	c++ -Wall -Wextra -Werror -g ./tests/map/mainFT.cpp -std=c++98 -o $(MAIN_MAP_FT) 

clean:
	rm -rf $(NAME) $(MAIN_VECTOR_FT) $(MAIN_VECTOR_STD) $(MAIN_MAP_STD) $(MAIN_MAP_FT) $(MAIN_STACK_FT) $(MAIN_STACK_STD) 

fclean: clean

re: fclean all