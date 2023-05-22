/**
 * @file elevator.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-22
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

class Elevator
{
    private:
        int floors;
        int elevators_count;
        int elevator_id;
        int current_floor;
        typedef enum State
        {
            UP, DOWN, STOPPED
        } State;
        State state;
        int destination_floor;
        void setState(State state)
        {
            this->state = state;
        }
        void setCurrentFloor(int floor)
        {
            current_floor = floor;
        }
        void setDestinationFloor(int floor)
        {
            destination_floor = floor;
        }
        void setFloors(int floors)
        {
            this->floors = floors;
        }
        void setFloorsCount(int count)
        {
            elevators_count = count;
        }
        void setElevatorId(int id)
        {
            elevator_id = id;
        }
    public:
        Elevator(int floors)
        {
            setFloors(floors);
            setCurrentFloor(1);
            setDestinationFloor(1);
            setState(STOPPED);
        }
        State getState()
        {
            return state;
        }
        int getCurrentFloor()
        {
            return current_floor;
        }
        int getDestinationFloor()
        {
            return destination_floor;
        }
        int getFloors()
        {
            return floors;
        }
        void moveUp()
        {
            if (current_floor < floors)
            {
                ++current_floor;
            }
        }
        void moveDown()
        {
            if (current_floor > 1)
            {
                --current_floor;
            }
        }
        void openDoor()
        {
            cout << "Opening door on floor " << current_floor << endl;
        }
        void closeDoor()
        {
            cout << "Closing door on floor " << current_floor << endl;
        }
        void move()
        {
            if (current_floor < destination_floor)
            {
                moveUp();
            }
            else if (current_floor > destination_floor)
            {
                moveDown();
            }
        }
        void call(int floor)
        {
            setDestinationFloor(floor);
            setState(STOPPED);
            openDoor();
            closeDoor();
            setState(UP);
            move();
            setState(STOPPED);
            openDoor();
            closeDoor();
        }
        void selectFloor(int floor)
        {
            setDestinationFloor(floor);
            setState(STOPPED);
            openDoor();
            closeDoor();
            setState(UP);
            move();
            setState(STOPPED);
            openDoor();
            closeDoor();
        }
        void selectFloor(int floor, int elevator_id)
        {
            setElevatorId(elevator_id);
            setDestinationFloor(floor);
            setState(STOPPED);
            openDoor();
            closeDoor();
            setState(UP);
            move();
            setState(STOPPED);
            openDoor();
            closeDoor();
        }
};

void simulateElevatorBehavior(Elevator& elevator, int floor)
{
    elevator.call(floor);
    elevator.selectFloor(floor);
    elevator.selectFloor(floor, 1);
}

void simulateMultipleElevatorsMultipleFloors(Elevator& elevator, int floor, int elevator_id)
{
    elevator.call(floor);
    elevator.selectFloor(floor);
    elevator.selectFloor(floor, elevator_id);
}

int main()
{
    Elevator elevator(10);
    elevator.call(5);
    elevator.selectFloor(7);
    elevator.selectFloor(3, 2);
    simulateElevatorBehavior(elevator, 5);
    simulateMultipleElevatorsMultipleFloors(elevator, 5, 2);
    return 0;
}
