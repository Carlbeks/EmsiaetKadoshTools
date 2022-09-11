#pragma once

#include "PreGlobal.h"

b ifloopMain_temp = true;
v f_MainProgress() {
	StepThreadBlocker.block(2);
	InnerMessage.PostInnerMessageLogU(LOG_DEBUG, "f_MainProgress 1");
	StepThreadBlocker.block();
	InnerMessage.PostInnerMessageLogU(LOG_DEBUG, "f_MainProgress 2");
	StepThreadBlocker.block();
	InnerMessage.PostInnerMessageLogU(LOG_DEBUG, "f_MainProgress 3");
	StepThreadBlocker.block();
	InnerMessage.PostInnerMessageLogU(LOG_DEBUG, "f_MainProgress 4");
	er;
}
v f_MainLoop() {
	while (ifloopMain_temp) {
		f_MainProgress();
	}
	std::cout << "f_MainLoop exit." << std::endl;
	er;
}

n InnerMsgProc(un3 c_, un3 f_, un3 i_, n t_) {
	er1;
}

v f_InnerMessageLoop() {
	std::cout << "f_InnerMessageLoop start." << std::endl;
	InnerMessage.Init(InnerMsgProc);
	EKMSG* pekmsg_ = new EKMSG;
	while (InnerMessage.GetInnerMessageS(pekmsg_)) {
		InnerMessage.DispatchInnerMessage(pekmsg_);
	}
	std::cout << "f_InnerMessageLoop exit." << std::endl;
	er;
}