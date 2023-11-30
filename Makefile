################################################################################################################################################
###        In this Makefile made by taka, you can use as                                                               	                     ###
###        $ make                     # You can get the executable file which written in TARGET.                                             ###
###        $ make hoge                # You can get the executable file which written in hoge.                                               ###
###        $ make clean               # The executable file which written in TARGET will removed.                                            ###
################################################################################################################################################


###sowaのメモ
####下のTARGET......endif は、ifeq内の内容、例えばgetinfo,calibがあると、
#そのさらに下のgetinfo→kargetinfo.cpp,calib→karcalib.cppの２つのcppファイルが,
#コマンドmakeをすることで同時に実行ファイルにすることができる
#その下にifeq ($(MAKECMDGOALS),clean)は,make cleanをすると,getinfoとcalibの実行ファイルが消える
#cleanの具体的な作用は一番下の内容になる
#clean:
#	rm -f *.o $(PROGRAM)

#実行ファイルにしたい場合, make getinfo/calib/joyなどなど
#getinfo : $(PROGRAM)
#setposq : $(PROGRAM)
#calib : $(PROGRAM)
#joy : $(PROGRAM)
#test: $(PROGRAM)
##test2: $(PROGRAM)
#sowa : $(PROGRAM)
#kargetinfo_sowa : $(PROGRAM)
#karsetposq_sowa : $(PROGRAM)
#左側の単語の内容をmake の後ろに入れることで、それに関連するcppファイルが実行ファイルになるls


TARGET=$(MAKECMDGOALS)
ifeq ($(MAKECMDGOALS),)
	TARGET=getinfo
	TARGET=calib
	TARGET=karset_sowa
	TARGET=setposq
	TARGET=joy
	TARGET=kargetinfo_sowa
endif
ifeq ($(MAKECMDGOALS),clean)
	TARGET=getinfo
	TARGET=calib
	TARGET=karset_sowa
	TARGET=setposq
	TARGET=joy
	TARGET=kargetinfo_sowa
endif


DIRX = /usr/X11R6/lib 
CXXFLAGS = -fpermissive -I/usr/include/eigen3   #追加したのは/Eigenのみ
LDFLAGS	 = -L "$(DIRX)"  -L/usr/lib -lm -pthread -std=c++11 

ifeq ($(TARGET),calib)
	SOURCE_MAIN = karcalib.cpp
	LDFLAGS += -pthread -lKARoperator 
endif

ifeq ($(TARGET),joy)
	SOURCE_MAIN = karjoystick.cpp
	LDFLAGS += -pthread -lKARoperator 
endif

ifeq ($(TARGET),getinfo)
	SOURCE_MAIN = kargetinfo.cpp
	LDFLAGS += -pthread -lKARoperator 
endif

ifeq ($(TARGET),setposq)
	SOURCE_MAIN = karsetposq.cpp
	LDFLAGS += -pthread -lKARoperator 
endif

ifeq ($(TARGET),test)
	SOURCE_MAIN = kartest.cpp
	LDFLAGS += -pthread -lKARoperator 
endif

ifeq ($(TARGET),test2)
	SOURCE_MAIN = kartest2.cpp
	LDFLAGS += -pthread -lKARoperator 
endif

ifeq ($(TARGET),sowa)
	SOURCE_MAIN = sowa.cpp
	LDFLAGS += -pthread -lKARoperator 
endif

ifeq ($(TARGET),kargetinfo_sowa)
	SOURCE_MAIN = kargetinfo_sowa.cpp
	LDFLAGS += -pthread -lKARoperator 
endif

ifeq ($(TARGET),karset_sowa)
	SOURCE_MAIN = karset_sowa.cpp
	LDFLAGS += -pthread -lKARoperator 
endif

#下の部分(52~55行目)の#を外して〇と?のところを書き換えよう

#ifeq ($(TARGET),〇〇)
#	SOURCE_MAIN = ????????.cpp
#	LDFLAGS += -pthread -lKARoperator 
#endif


PROGRAM = $(SOURCE_MAIN:%.cpp=%.out)
SUBOBJ = $(SOURCE_SUB:%.cpp=%.o)
MAINOBJ = $(SOURCE_MAIN:%.cpp=%.o)
PROGRAM += $(MAINOBJ)
PROGRAM += $(SUBOBJ)


getinfo : $(PROGRAM)
setposq : $(PROGRAM)
calib : $(PROGRAM)
joy : $(PROGRAM)
#test: $(PROGRAM)
#test2: $(PROGRAM)
#sowa : $(PROGRAM)
kargetinfo_sowa : $(PROGRAM)
karset_sowa : $(PROGRAM)
#〇〇: $(PROGRAM)
#上の行の#を外して〇〇にさっきと同じものを


%.out: %.o $(SUBOBJ)
	g++ -o $@ $^ $(LDFLAGS) -w
%.o : %.cpp
	g++ -o $@ $< -c $(CXXFLAGS) -w
clean:
	rm -f *.o $(PROGRAM) 