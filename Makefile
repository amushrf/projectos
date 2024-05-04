# Compiler
CC = g++

# Compiler flags
CFLAGS = -g -Wall

# Target executable
TARGET = project_cs641

# Build all targets
all: $(TARGET)

# Link object files to create the target executable
$(TARGET): main.o SystemState.o Event.o JobArrivalEvent.o Job.o QuantumEndEvent.o DeviceRequestEvent.o DeviceReleaseEvent.o DisplayEvent.o
	$(CC) $(CFLAFS) -o $(TARGET) main.o SystemState.o Event.o JobArrivalEvent.o QuantumEndEvent.o DeviceRequestEvent.o DeviceReleaseEvent.o DisplayEvent.o Job.o

# Compile main.cpp to create main.o
main.o: main.cpp Event.h SystemState.h
	$(CC) $(CFLAGS) -c main.cpp
	
# Compile SystemState.cpp to create SystemState.o
SystemState.o: SystemState.cpp SystemState.h Event.h Job.h
	$(CC) $(CFLAGS) -c SystemState.cpp
	
# Compile Event.cpp to create Event.o
Event.o: Event.cpp Event.h SystemState.h
	$(CC) $(CFLAGS) -c Event.cpp
	
# Compile JobArrivalEvent.cpp to create JobArrivalEvent.o
JobArrivalEvent.o: JobArrivalEvent.cpp JobArrivalEvent.h Event.h SystemState.h Job.h
	$(CC) $(CFLAGS) -c JobArrivalEvent.cpp
	
# Compile QuantumEndEvent.cpp to create QuantumEndEvent.o
QuantumEndEvent.o: QuantumEndEvent.cpp QuantumEndEvent.h Event.h SystemState.h Job.h
	$(CC) $(CFLAGS) -c QuantumEndEvent.cpp
	
# Compile DeviceRequestEvent.cpp to create DeviceRequestEvent.o
DeviceRequestEvent.o: DeviceRequestEvent.cpp DeviceRequestEvent.h Event.h SystemState.h Job.h
	$(CC) $(CFLAGS) -c DeviceRequestEvent.cpp
	
# Compile DeviceReleaseEvent.cpp to create DeviceReleaseEvent.o
DeviceReleaseEvent.o: DeviceReleaseEvent.cpp DeviceReleaseEvent.h Event.h SystemState.h Job.h
	$(CC) $(CFLAGS) -c DeviceReleaseEvent.cpp
	
# Compile DisplayEvent.cpp to create DisplayEvent.o
DisplayEvent.o: DisplayEvent.cpp DisplayEvent.h Event.h SystemState.h Job.h
	$(CC) $(CFLAGS) -c DisplayEvent.cpp
	
# Compile Job.cpp to create Job.o
Job.o: Job.cpp Job.h
	$(CC) $(CFLAGS) -c Job.cpp

# Clean the project by removing the target executable and object files
clean:
	$(RM) $(TARGET); $(RM) *.o
