//Cracked by Kafei
// /d/shenlong/sgjob/sgjob50000.c

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *sgjobs = ({
        ([      "sgjob":          "太极十三势",
                "sgjob_type":           "寻",
                "exp_bonus":             150,
                "pot_bonus":             40,
                "score":                 2
        ]),

        ([      "sgjob":          "旧竹片",
                "sgjob_type":           "寻",
                "exp_bonus":             150,
                "pot_bonus":             40,
                "score":                 2
        ]),

        ([      "sgjob":          "薄绢",
                "sgjob_type":           "寻",
                "exp_bonus":             150,
                "pot_bonus":             40,
                "score":                 2
        ]),

        ([      "sgjob":          "石板",
                "sgjob_type":           "寻",
                "exp_bonus":             50,
                "pot_bonus":             10,
                "score":                 1
        ]),

        ([      "sgjob":          "紫霞秘笈",
                "sgjob_type":           "寻",
                "exp_bonus":             200,
                "pot_bonus":             50,
                "score":                 2
        ]),

        ([      "sgjob":          "杖法图解",
                "sgjob_type":           "寻",
                "exp_bonus":             150,
                "pot_bonus":             40,
                "score":                 2
        ]),

        ([      "sgjob":          "碧磷针",
                "sgjob_type":           "寻",
                "exp_bonus":             160,
                "pot_bonus":             40,
                "score":                 2
        ]),

        ([      "sgjob":          "化尸粉",
                "sgjob_type":           "寻",
                "exp_bonus":             160,
                "pot_bonus":             40,
                "score":                 2
        ]),

        ([      "sgjob":          "香",
                "sgjob_type":           "寻",
                "exp_bonus":             60,
                "pot_bonus":             10,
                "score":                 1
        ]),

        ([      "sgjob":          "炼心弹",
                "sgjob_type":           "寻",
                "exp_bonus":             60,
                "pot_bonus":             10,
                "score":                 1
        ]),

        ([      "sgjob":          "蒙汗药",
                "sgjob_type":           "寻",
                "exp_bonus":             30,
                "pot_bonus":             5,
                "score":                 1
        ]),

        ([      "sgjob":          "蛇杖",
                "sgjob_type":           "寻",
                "exp_bonus":            120,
                "pot_bonus":             30,
                "score":                 2
        ]),

        ([      "sgjob":          "清心散",
                "sgjob_type":           "寻",
                "exp_bonus":            100,
                "pot_bonus":             30,
                "score":                 1
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),
        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "PK",
        ]),

        ([      "sgjob":          "PK",
        ]),

        ([      "sgjob":          "PK",
        ]),
});

void create() { seteuid(getuid()); }

mapping query_sgjob()
{
        return sgjobs[random(sizeof(sgjobs))];
}

