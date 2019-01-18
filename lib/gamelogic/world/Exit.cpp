#include <string>

class Exit{

	private:
		std::string exitName;
		std::string exitDescription;
		short cardinalDirection;
		unsigned int targetRoomID;

	public:
		Exit(std::string exName, std::string exDescription, short cDirection, int targetID)
			: exitName{exName},
			  exitDescription{exDescription},
			  cardinalDirection{cDirection},
			  targetRoomID{targetID}
		{}
		Exit()
			: exitName{"NO_EXIT_NAME"},
			  exitDescription{"NO_EXIT_DESCRIPTION"},
			  cardinalDirection{0},
			  targetRoomID{0}
		{}
		//getters
		std:string getName() const { return exitName; }
		std:string getDescription() const { return exitDescription; }
		short getDirection() const { return cardinalDirection; }
		unsigned int getTargetID() const { return targetRoomID; }
		//setters
		void setName(std::string newName) { exitName = newName; }
		void setDescription(std::string newDescription) { exitDescription = newDescription; }
		void setDirection(short newDirection) { cardinalDirection = newDirection; }
		void setTargetID(int newTargetID) { targetRoomID = newTargetID; }

};

