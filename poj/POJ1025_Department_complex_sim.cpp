// http://blog.csdn.net/wonderwangwang/article/details/8751909 
//Problem: 1025  Memory: 284K  Time: 0MS 
//Language: C++  Result: Accepted 

#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

#define FLOOR 11
#define ROOM 11
#define AGENT 26
#define TIMELEN 9
#define ROOMNUMLEN 5
#define LONGESTTIME 24*60*60

typedef struct visitEvent
{
	unsigned startTime;
	unsigned endTime;
	string action;
};

struct agent
{
	char code;//每个来访者的代码
	unsigned stayTime[FLOOR][ROOM];//stayTime[x][y]存储将要在x层的y房间待的时间，如果为0则表示不访问该房间
	unsigned enterTime;//将时间转化为秒，用一个整数来记录
	unsigned roomCnt;//要访问的房间数
	unsigned myCurrTime;//该来访者的当前时间，初始时为enterTime
	unsigned from;//房号xxyy或电梯号1到9，入口用0表示，出口用10表示
	unsigned to;//房号xxyy或电梯号1到9，入口用0表示，出口用10表示
	bool hasExited;//是否已经退出
	vector<visitEvent> myEvent;
}agents[AGENT];//所有26个可能的来访者

struct elevator
{
	unsigned enterTime;
	bool waitQueue[AGENT];//waitQueue[i]为true表示来访者i正在等该层的电梯
}elevators[FLOOR];//elevators[0]和elevators[10]未使用,elevators[1]指从1楼到2楼的电梯

struct room
{
	bool waitQueue[AGENT];//waitQueue[i]为true表示来访者i正在等该房间
	unsigned enterRoomTime;//进入房间的时间
	unsigned exitRoomTime;//离开房间的时间
}rooms[FLOOR][ROOM];

char mytime[TIMELEN];
char myroom[ROOMNUMLEN];
unsigned earliestTime = LONGESTTIME;
unsigned curTime;
unsigned visitorCnt = 0;

void SecToTime(unsigned sec);//将秒数转换为HH:MM:SS格式
void RoomToStr(unsigned floor, unsigned room);//将房号转换为xxyy字符串形式
bool NeedToWaitRoom(unsigned who,unsigned floor, unsigned room);
void WaitRoom(unsigned who,unsigned floor, unsigned room);
void VisitRoom(unsigned who, unsigned floor, unsigned room);//访问一个房间
void RoomToRoom(unsigned who,unsigned floor,unsigned room,unsigned nextRoom);
void RoomToElevator(unsigned who,unsigned floor,unsigned room);
unsigned FindDestRoom(unsigned who,unsigned floor,unsigned room);//返回下一个要去的房间
void EnterElevator(unsigned who,unsigned floor,unsigned dFloor);
bool NeedToWaitElevator(unsigned who,unsigned floor);
void WaitElevator(unsigned who,unsigned floor);
void ElevatorToRoom(unsigned who,unsigned floor,unsigned room);
void ExitBuilding(unsigned who,unsigned floor,unsigned room);
void Visit(unsigned who,unsigned floor,unsigned room);
void SolveConflict();
int cmp(const visitEvent* a,const visitEvent* b);

int main()
{
	char ch;//代码
	string et;//进入时间
	string roomID;//每一个房间号
	unsigned st;//欲在房间待的时间

	for(int i=0; i<FLOOR; i++)//初始化房间和电梯的等待队列
	{
		for(int j=0; j<AGENT; j++)
			elevators[i].waitQueue[j] = false;
		for(int k=0; k<ROOM; k++)
			for(int m=0; m<AGENT; m++)
				rooms[i][k].waitQueue[m] = false;
	}
	
	cin>>ch;
	while(ch != '.')
	{
		visitorCnt++;
		cin>>et;
		unsigned index = ch -'A';
		agents[index].code = ch;

		//将进入时间转换为秒
		unsigned hh,mm,ss;
		hh = (et[0]-'0')*10+(et[1]-'0');
		mm = (et[3]-'0')*10+(et[4]-'0');
		ss = (et[6]-'0')*10+(et[7]-'0');
		agents[index].enterTime = hh*60*60+mm*60+ss;
		agents[index].myCurrTime = agents[index].enterTime + 30;
		if(agents[index].myCurrTime<earliestTime)
			earliestTime = agents[index].myCurrTime;

		visitEvent e;
		e.startTime = agents[index].enterTime;
		e.endTime = agents[index].enterTime+30;
		e.action = "Entry";
		agents[index].from = 0;
		agents[index].hasExited = false;

		memset(agents[index].stayTime, 0, sizeof(agents[index].stayTime));
		agents[index].roomCnt = 0;

		cin>>roomID;
		while(roomID.compare("0"))
		{
			cin>>st;
			agents[index].roomCnt++;
			int floor,room;
			floor = (roomID[0]-'0')*10 + (roomID[1]-'0');
			room = (roomID[2]-'0')*10 + (roomID[3]-'0');
			agents[index].stayTime[floor][room] = st;

			if(agents[index].roomCnt == 1)//第一个要去的房间
			{
				if(floor>1)
					agents[index].to = 1;//如果第一个要去的房间不在1楼就去1楼的电梯
				else
					agents[index].to = floor*100 + room;
			}


			cin>>roomID;
		}
		agents[index].myEvent.push_back(e);
		
		cin>>ch;
	}

	unsigned i;
	for(curTime=earliestTime; curTime<LONGESTTIME; curTime++)
	{
		for(i=0; i<AGENT; i++)
		{
			if(agents[i].myCurrTime==curTime)
			{
				if(agents[i].roomCnt>0 || agents[i].to == 1)
				{
					if(agents[i].from==0 && agents[i].to>0 && agents[i].to<FLOOR)//入口->电梯
					{
						unsigned destRoom = FindDestRoom(i,agents[i].to,0);//目标楼层
						if(NeedToWaitElevator(i,agents[i].to))
							WaitElevator(i,agents[i].to);
						else
						{
							EnterElevator(i,agents[i].to,destRoom);
							agents[i].from = destRoom;
							agents[i].to = FindDestRoom(i,agents[i].from,0);
						}
					}
					else if(agents[i].from==0 && agents[i].to>FLOOR)//入口->房间
					{
						if(NeedToWaitRoom(i,agents[i].to/100,agents[i].to%100))
							WaitRoom(i,agents[i].to/100,agents[i].to%100);
						else
						{
							VisitRoom(i,agents[i].to/100,agents[i].to%100);
							agents[i].from = agents[i].to;
							agents[i].to = FindDestRoom(i,agents[i].to/100,agents[i].to%100);
							if(agents[i].to == 1)//只访问1楼的房间时会出现这种情况
								 agents[i].to = 0;
						}
					}
					else if(agents[i].from>0 && agents[i].from<FLOOR && agents[i].to>FLOOR)//电梯->房间
					{
						ElevatorToRoom(i,agents[i].to/100,agents[i].to%100);
						agents[i].from = agents[i].to;
					}
					else if(agents[i].from==agents[i].to && agents[i].from>FLOOR)//待在房间里
					{
						if(NeedToWaitRoom(i,agents[i].to/100,agents[i].to%100))
							WaitRoom(i,agents[i].to/100,agents[i].to%100);
						else
						{
							VisitRoom(i,agents[i].to/100,agents[i].to%100);
							agents[i].to = FindDestRoom(i,agents[i].to/100,agents[i].to%100);
						}
					}
					else if(agents[i].from>FLOOR && agents[i].to>FLOOR)//房间->房间
					{
						RoomToRoom(i,agents[i].from/100,agents[i].from%100,agents[i].to%100);
						agents[i].from = agents[i].to;
					}
					else if(agents[i].from>FLOOR && agents[i].to>0 && agents[i].to<FLOOR)//房间->电梯，该层已经访问完
					{
						RoomToElevator(i,agents[i].from/100,agents[i].from%100);
						agents[i].from = agents[i].from/100;
					}
					else if(agents[i].from>0 && agents[i].from<FLOOR && agents[i].to>0 && agents[i].to<FLOOR)//需要乘电梯从agents[i].from楼到agents[i].to楼
					{
						if(NeedToWaitElevator(i,agents[i].from))
							WaitElevator(i,agents[i].from);
						else
						{
							EnterElevator(i,agents[i].from,agents[i].to);
							if(agents[i].to !=1)
							{
								agents[i].from = agents[i].to;
								agents[i].to = FindDestRoom(i,agents[i].to,0);
							}
							else
								agents[i].to = 0;//已经下到第一层，去出口
						}
					}
					else
						cout<<"Others------"<<agents[i].code<<"from:"<<agents[i].from<<"to:"<<agents[i].to<<endl;
				}
				else if(agents[i].hasExited == false)
					ExitBuilding(i,agents[i].from/100,agents[i].from%100);
			}
		}
		if(visitorCnt == 0)//所有访问者均已访问完毕
			break;
	}

	//输出
	for(i=0; i<AGENT; i++)
	{
		if(isupper(agents[i].code))
		{
			cout<<agents[i].code<<endl;
			for(vector<visitEvent>::iterator iter=agents[i].myEvent.begin(); iter!=agents[i].myEvent.end(); ++iter)
			{
				SecToTime(iter->startTime);
				cout<<mytime<<" ";
				SecToTime(iter->endTime);
				cout<<mytime<<" " <<iter->action<<endl;
			}
			cout<<endl;
		}
	}
	return 0;
}

bool NeedToWaitRoom(unsigned who,unsigned floor, unsigned room)//有人已经在房间里或者有优先级高的人在等房间，则返回true,需要等待
{
	int i;
	for(i=0; i<who; i++)
	{
		if(rooms[floor][room].waitQueue[i])
			break;
	}
	if(i<who || rooms[floor][room].exitRoomTime>curTime)
		return true;
	else
		return false;
}
void WaitRoom(unsigned who,unsigned floor, unsigned room)
{
	unsigned waitCnt = 0;
	unsigned queueTime = 0;//排队时间
	int i;
	visitEvent e;

	rooms[floor][room].waitQueue[who] = true;
	e.startTime = agents[who].myCurrTime;
	for(i=0; i<who; i++)
	{
		if(rooms[floor][room].waitQueue[i])//说明有优先级更高的人在等房间
		{
			queueTime += agents[i].stayTime[floor][room];
		}
	}
	agents[who].myCurrTime = rooms[floor][room].exitRoomTime+queueTime;

	e.endTime = agents[who].myCurrTime;
	e.action = "Waiting in front of room ";
	RoomToStr(floor,room);
	e.action += myroom;
	agents[who].myEvent.push_back(e);
}
void VisitRoom(unsigned who, unsigned floor, unsigned room)
{
	visitEvent e;

	rooms[floor][room].waitQueue[who] = false;
	e.startTime = agents[who].myCurrTime;

	
	rooms[floor][room].enterRoomTime = agents[who].myCurrTime;
	agents[who].roomCnt--;
	
	agents[who].myCurrTime += agents[who].stayTime[floor][room];
	rooms[floor][room].exitRoomTime = agents[who].myCurrTime;

	e.endTime = agents[who].myCurrTime;
	e.action = "Stay in room ";
	RoomToStr(floor,room);
	e.action += myroom;
	agents[who].myEvent.push_back(e);
	
}

void RoomToRoom(unsigned who,unsigned floor,unsigned room,unsigned nextRoom)
{
	visitEvent e;

	e.startTime = agents[who].myCurrTime;
	
	agents[who].myCurrTime += 10;
	e.endTime = agents[who].myCurrTime;
	e.action = "Transfer from room ";
	RoomToStr(floor,room);
	e.action += myroom;
	e.action += " to room ";
	RoomToStr(floor,nextRoom);
	e.action += myroom;
	agents[who].myEvent.push_back(e);

}

void RoomToElevator(unsigned who,unsigned floor,unsigned room)
{
	visitEvent e;

	e.startTime = agents[who].myCurrTime;
	agents[who].myCurrTime += 10;
	e.endTime = agents[who].myCurrTime;
	e.action = "Transfer from room ";
	RoomToStr(floor,room);
	e.action += myroom;
	e.action += " to elevator";
	agents[who].myEvent.push_back(e);
}
bool NeedToWaitElevator(unsigned who,unsigned floor)//返回True表示需要等电梯
{
	int i;
	for(i=0; i<who; i++)
	{
		if(elevators[floor].waitQueue[i])
			break;
	}
	if(curTime%5 || i<who || agents[who].myCurrTime<=elevators[floor].enterTime)
		return true;
	else
		return false;
}
unsigned FindDestRoom(unsigned who,unsigned floor,unsigned room)//返回下一个要去的房间
{
	unsigned f,r;
	f=floor;
	r = room+1;
	for(; f<FLOOR; f++)
	{
		for(; r<ROOM; r++)
		{
			if(agents[who].stayTime[f][r])
			{
				if(f==floor)
					return f*100+r;
				else//在同一楼层没有要访问的房间，去电梯
					return f;
			}
		}
		r = 1;
	}
	if(f == FLOOR)//所有房间都访问完则去1楼
		return 1;
}
void EnterElevator(unsigned who,unsigned floor,unsigned dFloor)
{
	visitEvent e;

	elevators[floor].waitQueue[who] = false;
	elevators[floor].enterTime = agents[who].myCurrTime;
	e.startTime = agents[who].myCurrTime;

	agents[who].myCurrTime += 30*(dFloor>floor?dFloor-floor:floor-dFloor);
	if(dFloor==floor)
		agents[who].myCurrTime += 30;
	e.endTime = agents[who].myCurrTime;
	e.action = "Stay in elevator";
	agents[who].myEvent.push_back(e);
}
void WaitElevator(unsigned who,unsigned floor)
{
	unsigned waitCnt = 0;
	unsigned waitTime = 0;//需要等待的时间
	int i;
	visitEvent e;

	elevators[floor].waitQueue[who] = true;
	e.startTime = agents[who].myCurrTime;
	for(i=0; i<who; i++)
	{
		if(elevators[floor].waitQueue[i])
			waitCnt++;
	}
	if(waitCnt>0)//说明有优先级更高的人在等电梯
		waitTime = waitCnt*5 + 5-curTime%5;
	else
		waitTime = 5-curTime%5;

	agents[who].myCurrTime += waitTime;
	
	e.endTime = agents[who].myCurrTime;
	e.action = "Waiting in elevator queue";
	agents[who].myEvent.push_back(e);
}
void ElevatorToRoom(unsigned who,unsigned floor,unsigned room)
{
	visitEvent e;

	e.startTime = agents[who].myCurrTime;
	agents[who].myCurrTime += 10;
	e.endTime = agents[who].myCurrTime;
	e.action = "Transfer from elevator to room ";
	RoomToStr(floor,room);
	e.action += myroom;

	agents[who].myEvent.push_back(e);
}
void ExitBuilding(unsigned who,unsigned floor,unsigned room)
{
	visitEvent e;

	e.startTime = agents[who].myCurrTime;
	agents[who].myCurrTime += 30;
	e.endTime = agents[who].myCurrTime;
	e.action = "Exit";
	agents[who].myEvent.push_back(e);
	agents[who].hasExited = true;
	visitorCnt--;
}

//将秒数转换为HH:MM:SS格式
void SecToTime(unsigned sec)
{
	unsigned hh,mm,ss;

	hh = sec/3600;
	mm = (sec%3600)/60;
	ss = (sec%3600)%60;

	if(hh<10)
		_snprintf(mytime, 3, "0%d:", hh);
	else
		_snprintf(mytime, 3, "%d:", hh);

	if(mm<10)
		_snprintf(mytime+3, 3, "0%d:", mm);
	else
		_snprintf(mytime+3, 3, "%d:", mm);

	if(ss<10)
		_snprintf(mytime+6, 2, "0%d", ss);
	else
		_snprintf(mytime+6, 2, "%d", ss);

	mytime[TIMELEN-1] = '\0';
}

//将房号转换为xxyy字符串形式
void RoomToStr(unsigned floor, unsigned room)
{
	if(floor<10)
		_snprintf(myroom, 2, "0%d:", floor);
	else
		_snprintf(myroom, 2, "%d:", floor);
	if(room<10)
		_snprintf(myroom+2, 2, "0%d:", room);
	else
		_snprintf(myroom+2, 2, "%d:", room);

	myroom[ROOMNUMLEN-1]= '\0';

}


