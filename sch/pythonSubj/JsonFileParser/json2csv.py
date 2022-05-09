# coding=utf-8

import os.path
import pandas as pd


def make_copy(srcFile, n):
    # type: (String, Integer) -> List

    if not os.path.isfile(srcFile):
        print("[에러] 복사 할 파일이 없습니다.")
        exit(-1)

    data = pd.read_json(srcFile)

    jsonList = list()
    while(n>0):
        #json 내용을 복제할 파일에 맞게 수정합니다.
        destFile = srcFile.replace(".json", "{}.json".format(n))
        data["filename"] = "test{}.json".format(n)
        data["path"] = "project\\test{}.json".format(n)
        data.to_json(destFile)
        jsonList.append(destFile)
        n -= 1
    return jsonList


def delete_copy(copyList):
    # :type copyList: List
    for file in copyList:
        if os.path.exists(file):
            os.remove(file)


def make_csv(mergeList, csvPath):
    tmp_df = []
    for jsonPath in mergeList:
        print(jsonPath)
        tmp_df.append(pd.read_json(jsonPath))
    df = pd.concat(tmp_df)
    df.to_csv(csvPath, index=False)