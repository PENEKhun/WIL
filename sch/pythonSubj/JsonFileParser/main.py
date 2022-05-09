# coding=utf-8
#정보보호학과 20194581 문성훈

import json2csv


if __name__ == '__main__':
    #json파일을 10개 복제합니다
    jsonList = json2csv.make_copy("./test.json", 10)

    #CSV파일로 만듭니다.
    json2csv.make_csv(jsonList, "./result.csv")

    #복제한 json파일을 제거합니다.
    json2csv.delete_copy(jsonList)