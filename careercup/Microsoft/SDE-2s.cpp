#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <chrono>

using namespace std;

struct Subscriber
{
	std::string username;
	std::string password;
	void(*callback)(std::string message);

	Subscriber(std::string username, std::string password, void(*cb)(std::string message) ){

		this->username = username;
		this->password = password;
		this->callback = cb;
	}
};

struct Queue{
	std::string name;
	vector<Subscriber*> subscribers;
	Queue(std::string name){
		this->name = name;
	}
};

struct Event{

	vector<Queue*> queues;

	Queue* addQueue(std::string name){

		Queue *q = new Queue(name);
		this->queues.push_back(q);
		return q;
	}

	Queue *getQueue(std::string name){
		for (int i = 0; i < this->queues.size(); ++i){
			if(this->queues[i]->name == name){
				return this->queues[i];
			}
		}
		return NULL;
	}
	void addSubscriber(Queue *q, Subscriber *subscriber){

		q->subscribers.push_back(subscriber);

		// Print message when new subscriber joined.
		std::cout << "Username: " << subscriber->username << std::endl;
		std::cout << "Password: " << subscriber->password << std::endl;

	}
	void publish(std::string message, std::string queueName){

		Queue *queue = this->getQueue(queueName);

		if(queue != NULL){
			for (int i = 0; i < queue->subscribers.size(); ++i){
				queue->subscribers[i]->callback(message);
			}
		}

	
	}

	void listen(int port){
		std::cout << "The queue is running on port: " << port << std::endl;
		while(true){
			
		}
	}

};

/*
* This is function callback when receive message of the queue
*/
void messageReceivedCallback(std::string message){
	std::cout << "Received message:" << message << endl;
}


Event even;
/**
* Start event service and wait for message
**/
void runEvent(){

	Queue *queue = even.addQueue("Demo"); // create new queue demo for subscribers
	
	//New subscriber
	Subscriber *subscriber = new Subscriber("admin", "admin", messageReceivedCallback);
	even.addSubscriber(queue, subscriber);
	even.listen(8161);

}

/**
*/
void pushMessage(){

	// loop and send message every 3 seconds

	while(true){

		std::this_thread::sleep_for (std::chrono::seconds(2));

		even.publish("New message.", "Demo");
	}
}

int main(int argc, char const *argv[]){
		
	std::thread eventThread(runEvent);
	std::thread pushMessageThread(pushMessage);
	eventThread.join();
	pushMessageThread.join();

	return 0;
}