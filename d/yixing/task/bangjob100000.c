//Cracked by Kafei
// /d/huanghe/bangjob/bangjob100000.c

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "萧半和",
                "file"  :  "/d/forest/npc/banhe",
                "area"  :  "扬州郊外",
                "type"  :  "杀",
                "bonus" :  50,
                "score" :  15,
        ]),

        ([      "name"  :  "侯通海",
                "file"  :  "/d/huanghe/npc/hou-tonghai",
                "area"  :  "黄河岸边",
                "type"  :  "杀",
                "bonus" :  30,
                "score" :  10,
        ]),

        ([      "name"  :  "戚长发",
                "file"  :  "/d/foshan/npc/changfa",
                "area"  :  "湘西",
                "type"  :  "杀",
                "bonus" :  30,
                "score" :  10,
        ]),

        ([      "name"  :  "黄钟公",
                "file"  :  "/d/jiaxing/npc/huang",
                "area"  :  "杭州梅庄",
                "type"  :  "杀",
                "bonus" :  75,
                "score" :  25,
        ]),

        ([      "name"  :  "黑白子",
                "file"  :  "/d/jiaxing/npc/heibai",
                "area"  :  "杭州梅庄",
                "type"  :  "杀",
                "bonus" :  70,
                "score" :  20,
        ]),

        ([      "name"  :  "秃笔翁",
                "file"  :  "/d/jiaxing/npc/tubiweng",
                "area"  :  "杭州梅庄",
                "type"  :  "杀",
                "bonus" :  65,
                "score" :  20,
        ]),

        ([      "name"  :  "丹青生",
                "file"  :  "/d/jiaxing/npc/danqing",
                "area"  :  "杭州梅庄",
                "type"  :  "杀", 
                "bonus" :  60,
                "score" :  17,
        ]),

        ([      "name"  :  "丁坚",
                "file"  :  "/d/jiaxing/npc/dingjian",
                "area"  :  "杭州梅庄",
                "type"  :  "杀",
                "bonus" :  45,
                "score" :  10,
        ]),

        ([      "name"  :  "施令威",
                "file"  :  "/d/jiaxing/npc/shilingwei",
                "area"  :  "杭州梅庄",
                "type"  :  "杀",
                "bonus" :  40,
                "score" :  10,
        ]),

        ([      "name"  :  "陆冠英",
                "file"  :  "/d/taihu/npc/guanying",
                "area"  :  "归云庄",
                "type"  :  "杀",
                "bonus" :  60,
                "score" :  20,
        ]),

        ([      "type"  :  "截镖",
        ]),

        ([      "type"  :  "截镖",
        ]),

        ([      "type"  :  "截镖",
        ]),

        ([      "type"  :  "示威",
        ]),

        ([      "type"  :  "示威",
        ]),

        ([      "type"  :  "示威",
        ]),

        ([      "type"  :  "示威",
        ]),

        ([      "type"  :  "示威",
        ]),

        ([      "type"  :  "示威",
        ]),

        ([      "type"  :  "示威",
        ]),

        ([      "type"  :  "示威",
        ]),
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}

