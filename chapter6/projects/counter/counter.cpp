/**
 * @file counter.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" //always include for every new hpp and cpp file

using namespace std;

class Counter {
    public:
        Counter creator();
        void setIncrementStep(int newIncrementStep);
        void setDecrementStep(int newDecrementStep);
        void setCount(int newCount);
        void increment();
        void decrement();
        void resetCounter();
        int getCount();
        int setCurrentCount();
        int getIncrementStep();
        int getDecrementStep();
        int getResetCount();
		void print();
        Counter destructor();
    private:
        int incrementStep;
        int counter;
        int decrementStep;
        int resetCount;
};

int main(int argc,char **argv);

/**
 * @brief function definitions for class Counter
 * 
 */

int incrementStep;
int _counter; 
int decrementStep;
int resetCount;

Counter Counter::creator() {
  Counter newCounter;
  newCounter.setIncrementStep(1);
  newCounter.setDecrementStep(1);
  newCounter.setCount(0);
  return newCounter;
}

void Counter::setIncrementStep(int newIncrementStep) {
  incrementStep = newIncrementStep;
}

void Counter::setDecrementStep(int newDecrementStep) {
  decrementStep = newDecrementStep;
}

void Counter::setCount(int newCount) {
  _counter = newCount;
}

void Counter::increment() {
  _counter += incrementStep;
}

void Counter::decrement() {
   _counter -= decrementStep;
   /**
    * @brief if _counter is less than 0, set _counter to 0
    * 
    */
   if (_counter < 0) {
     _counter = 0;
   }
   else if (_counter > 0)
   {
        _counter -= decrementStep;
   }
}

void Counter::resetCounter() {
  _counter = resetCount;
}

int Counter::getCount() {
  return _counter;
}

int Counter::setCurrentCount() {
  return _counter;
}

int Counter::getIncrementStep() {
  return incrementStep;
}

int Counter::getDecrementStep() {
  return decrementStep;
}

int Counter::getResetCount() {
  return resetCount;
}

Counter Counter::destructor() {
  Counter newCounter;
  newCounter.setIncrementStep(0);
  newCounter.setDecrementStep(0);
  newCounter.setCount(0);
  return newCounter;
}

void Counter::print() {
  cout << "The current count is: " << _counter << endl;
}

int main(int argc, char **argv) {
	Counter counter1;
	counter1.creator();
	counter1.setIncrementStep(1);
	counter1.setDecrementStep(1);
	counter1.setCount(0);
	/**
	* @brief use a loop to count up to 10 and then down to 0
	* 
	*/
 	for (int i = 0; i < 10; i++) {
	counter1.increment();
	counter1.print();
	}
	counter1.setCount(10);
	counter1.setDecrementStep(1);
	for (int i = 0; i < 10; i++) {
	counter1.decrement();
	counter1.print();
	}
	counter1.destructor();
  	return 0;
}

