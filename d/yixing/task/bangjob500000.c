//Cracked by Kafei
// /d/huanghe/bangjob/bangjob500000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "丁典",
                "file"  :  "/d/city/npc/dingdian",
                "area"  :  "扬州城监狱",
                "type"  :  "杀",
                "bonus" :  100,
                "score" :  40,
        ]),

        ([      "name"  :  "滕一雷",
                "file"  :  "/d/changbai/npc/teng",
                "area"  :  "关东",
                "type"  :  "杀",
                "bonus" :  70,
                "score" :  20,
        ]),

        ([      "name"  :  "彭连虎",
                "file"  :  "/d/forest/npc/peng-lianhu",
                "area"  :  "黄河帮",
                "type"  :  "杀",
                "bonus" :  60,
                "score" :  15,
        ]),

        ([      "name"  :  "玄铁令",
                "file"  :  " ",
                "type"  :  "寻",
                "bonus" :  50,
                "score" :  12,
        ]),
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}
