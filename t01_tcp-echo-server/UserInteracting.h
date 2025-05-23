
#ifndef USER_INTERACTING_H
#define USER_INTERACTING_H

#include <string>

#include "Processing.h"
#include "TcpTransfering.h"

class UserInteracting : public Processing
{

public:

	static UserInteracting *create(int fdPeer)
	{
		return new dNoThrow UserInteracting(fdPeer);
	}

	UserInteracting(int fdPeer);

protected:

	UserInteracting() = delete;
	virtual ~UserInteracting() {}

private:

	UserInteracting(const UserInteracting &) = delete;
	UserInteracting &operator=(const UserInteracting &) = delete;

	Success process();
	Success shutdown();
	Success msgReceive(std::string &msg);
	void processInfo(char *pBuf, char *pBufEnd);

	uint32_t mStateSd;
	int mFdPeer;
	TcpTransfering *mpConn;
	std::string mMsgLast;
	bool mQuitByUser;

};

#endif

