#include <iostream>
#include <cstdlib>

class Receiver
{
public:
	virtual ~Receiver() {};
	
	virtual void Action() {};
};

class Processor : public Receiver 
{
public:
	void UnlockScreen()
	{
		std::cout << "unlock screen..." << std::endl;
	}
	
	void StartApp()
	{
		std::cout << "start app..." << std::endl;
	}
	
	void LockScreen()
	{
		std::cout << "lock screen..." << std::endl;
	}
};

class SoundCard : public Receiver
{
public:
	void IncreaseSound()
	{
		std::cout << "increase sound..." << std::endl;
	}
	
	void DecreaseSound()
	{
		std::cout << "decrease sound..." << std::endl;
	}
};


class Command
{
public:
	virtual ~Command() {};
	
	virtual void Execute() = 0;

protected:
	Command() {};  // ?
};


class LockScreenCommand : public Command
{
public:
	LockScreenCommand(Processor *processor)
	{
		mProcessor = processor;
	}
	
	void Execute()
	{
		mProcessor->LockScreen();
	}

private:
	Processor *mProcessor;
};

class UnlockScreenCommand : public Command
{
public:
	UnlockScreenCommand(Processor *processor)
	{
		mProcessor = processor;
	}
	
	void Execute()
	{
		mProcessor->UnlockScreen();
	}
	
private:
	Processor *mProcessor;
};

class IncSoundCommand : public Command
{
public:
	IncSoundCommand(SoundCard *soundCard);
	virtual void Execute();

private:
	SoundCard *mSoundCard;
};


// Invoker
class Phone 
{
public:
	Phone() : mCommand(NULL) {};
	void SetCommand(Command *command)
	{
		mCommand = command;
	}
	
	void RunCommand()
	{
		mCommand->Execute();
	}
	
private:
	Command *mCommand;
};

class User
{
public:
	User();
	
	void BuyPhone();
	void LockScreen();
	void UnlockScreen();
	void StartApp();
	void IncSound();
	void DecSound();

private:
	Phone *mPhone;
	Processor *mProcessor;
	SoundCard *mSoundCard;
};

int main(int argc, char *argv[])
{
	User *user = new User();
	user->UnlockScreen();
	//user->StartApp();
	//user->IncSound();
	//user->DecSound();
	user->LockScreen();
	
	return (0);
}

User::User() : mPhone(NULL), mProcessor(NULL), mSoundCard(NULL)
{
	mPhone = new Phone();
	mProcessor = new Processor();
	mSoundCard = new SoundCard();
}

void User::UnlockScreen()
{
	Command *cmd = new UnlockScreenCommand(mProcessor);
	mPhone->SetCommand(cmd);
	mPhone->RunCommand();
}

void User::LockScreen()
{
	Command *cmd = new LockScreenCommand(mProcessor);
	mPhone->SetCommand(cmd);
	mPhone->RunCommand();
}















