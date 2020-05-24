// Room: /d/taishan/duzunju.c
// Last Modified by Winder on Aug. 25 2001
// Modified by Zeratul Jan 11 2001 江湖阅历低于10000不能见盟主

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "独尊居");
	set("long", @LONG
这里是处于岱顶后山的天下大宗师居所。青竹扎就的居所，东西两
面开着窗户，窗外还是青绿的竹林和林间透进的白云。北面墙上是一幅
中堂，痛快淋漓地三个大字草书：[31;1m
                            大
                            宗
                            师[0m
    大宗师在这里会见天下的英豪，品评他们的武功。如果你愿意接受
品评，就问问大宗师，看他是否愿意出手吧。不过要小心，生死与天神
巫师不相干的哦。
LONG );
	set("exits", ([
		"out" : __DIR__"fengchan",
	]));
	set("objects",([
		"/clone/npc/dazongshi" : 1,
	]));
	set("coor/x", 410);
	set("coor/y", 650);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}

