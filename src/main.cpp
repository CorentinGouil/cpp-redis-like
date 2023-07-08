#include "RedisServer.h"

int main() {
    RedisServer redisServer(6379, 2);
    redisServer.spawnServer();

    return 0;
}
