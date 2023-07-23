#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

typedef struct {
    int machineId;
    int time;
} MachineInfo;

typedef struct {
    int itemId;
    int sequenceId;
} SequenceInfo;

int main()
{
    int machine, number;
    scanf("%d %d", &machine, &number);
    
    // 读入加工顺序
    int sequences[number * machine];
    for (int i = 0; i < machine * number; i++)
    {
        int temp;
        scanf("%d", &temp);
        temp--;
        sequences[i] = temp;
    }

    // 第一个参数表示工件编号
    // 第二个参数表示步骤编号
    MachineInfo items[number][machine];

    // 读取每个步骤使用的机器编号
    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < machine; j++)
        {
            int temp;
            scanf("%d", &temp);
            items[i][j].machineId = temp - 1;
        }
    }

    // 读取每个步骤需要的时间
    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < machine; j++)
        {
            int temp;
            scanf("%d", &temp);
            items[i][j].time = temp;
        }
    }
    
    // 机器的状态
    char machineStates[machine][100001];
    memset(machineStates, 0, sizeof(char) * machine * 100001);
    // 工件当前执行的步数
    int steps[20] = {0};
    // 工件上一步完成的时间
    int lastTime[20] = {0};
    
    int max = 0;
    for (int i = 0; i < machine * number; i++)
    {
        int machineId = items[sequences[i]][steps[sequences[i]]].machineId;
        int time = items[sequences[i]][steps[sequences[i]]].time;

        // 找到足够的时间加工工件
        int enoughTime = 0;
        for (int j = lastTime[sequences[i]] + 1; ; j++)
        {
            if (machineStates[machineId][j] == 0)
            {
                enoughTime++;
            }
            else
            {
                enoughTime = 0;
            }

            if (enoughTime == time)
            {
                // 找到足够的时间
                for (int t = j - time + 1; t <= j; t++)
                {
                    machineStates[machineId][t] = 1;
                }

                max = j > max ? j : max;
                lastTime[sequences[i]] = j;
                break;                
            }
        }
        // 完成一个步骤
        steps[sequences[i]]++;
    }

    printf("%d\n", max);
    return 0;
}