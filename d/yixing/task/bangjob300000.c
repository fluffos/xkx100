//Cracked by Kafei
// /d/huanghe/bangjob/bangjob300000.c
// by aln / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "宝树",
                "file"  :  "/d/foshan/npc/baoshu",
                "area"  :  "少林寺",
                "type"  :  "杀",
                "bonus" :  40,
                "score" :  12,
        ]),

        ([      "name"  :  "梁子翁",
                "file"  :  "/d/huanghe/npc/liang-ziweng",
                "area"  :  "黄河帮",
                "type"  :  "杀",
                "bonus" :  70,
                "score" :  30,
        ]),

        ([      "name"  :  "日本浪人",
                "file"  :  "/d/quanzhou/npc/langren",
                "area"  :  "泉州",
                "type"  :  "杀",
                "bonus" :  30,
                "score" :  7,
        ]),

        ([      "name"  :  "杨铁心",
                "file"  :  "/d/hangzhou/npc/yang",
                "area"  :  "牛家村",
                "type"  :  "杀",
                "bonus" :  30,
                "score" :  10,
        ]),

        ([      "name"  :  "郭啸天",
                "file"  :  "/d/hangzhou/npc/guo",
                "area"  :  "牛家村",
                "type"  :  "杀",
                "bonus" :  30,
                "score" :  10,
        ]),

        ([      "name"  :  "虎骨",
                "file"  :  "  ",
                "type"  :  "寻",
                "bonus" :  30,
                "score" :  10,
        ]),

        ([      "name"  :  "熊胆",
                "file"  :  "  ",
                "type"  :  "寻",
                "bonus" :  40,
                "score" :  12,
        ]),

        ([      "name"  :  "指环",
                "file"  :  "  ",
                "type"  :  "寻",
                "bonus" :  25,
                "score" :  10,
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

        ([      "type"  :  "送礼",
        ]),

        ([      "type"  :  "送礼",
        ]),

        ([      "type"  :  "送礼",
        ]),

        ([      "type"  :  "送礼",
        ]),

        ([      "type"  :  "送礼",
        ]),
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}
