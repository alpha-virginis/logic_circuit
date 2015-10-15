
SOURCE = main.cpp calc.cpp table.cpp
OBJECT = $(SOURCE:%.cpp=%.o)
TARGET = logic_circuit

$(TARGET) : $(OBJECT)
	g++ -Wall -W -O2 -o $(TARGET) $(OBJECT) -lm

.cpp.o :
	g++ -Wall -W -O2 -c $< -lm

clean :
	rm *.o $(TARGET)
