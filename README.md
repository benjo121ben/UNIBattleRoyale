INSTALL:
Clone the repository and just run cmake. Then you should be fine.

If you wanna take a look at the files:
EventText is saved inside the EventSystem/EventTextStorage/EventTextStorageContainer.\
If you want to add an event to an existing EventType, you can just add the text into the appropriate vector.\
Make sure to use the provided function MakeQuery to get what you need from the system.\
The Vars::KEY_*  describe the variable you want to access\
and the Lambdas::LM_* functions return the keys to lambda functions used to access the relevant information.\

For example:\
makeQuery(Vars::KEY_PLAYER(), Lambdas::LM_PLAYER_POSESSIVE())\
makes the translator accesses the key_player variable (the player triggering the Event), outputting the player possessive pronoun when the Event is raised.\
makeQuery(Vars::KEY_PLAYER(), Lambdas::LM_PLAYERNAME())
accesses the same variable, but returns the players name instead.