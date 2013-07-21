#include <stdio.h>
#include <vector>
#include <map>
#include <stdint.h>
using namespace std;

uint32_t hash_id(uint32_t id) {
    return id % 3;
}

static uint32_t ERROR_ADDR = 0xFFFF;
typedef struct Entry {
    uint32_t key;
    uint32_t value;
    uint32_t next;
} Entry;

vector<Entry> g_items;
map<uint32_t, uint32_t> g_key_map;

int load() {
    uint32_t i = 0;
    for (i = 0; i < 5; i ++) {
    
        printf("please input key, value:\n");
        uint32_t key, value;
        scanf("%u %u", &key, &value);
        map<uint32_t, uint32_t>::iterator it;
        it = g_key_map.find(hash_id(key));
        if (it != g_key_map.end()) {
            Entry en;
            en.key = key;
            en.value = value;
            en.next = it->second;
            g_key_map[hash_id(key)] = g_items.size();
            g_items.push_back(en);
        } else {
            Entry en;
            en.key = key;
            en.value = value;
            en.next = ERROR_ADDR;
            g_key_map[hash_id(key)] = g_items.size();
            g_items.push_back(en);

        }
    }
    return 0;
}

int print() {
    map<uint32_t, uint32_t>::iterator it;
    for (it = g_key_map.begin(); it != g_key_map.end(); it ++) {
        printf("hash key is %u, add: %u\n", it->first, it->second );
        Entry *en = &g_items[it->second];
        
        printf("key:%u;value:%u; next:%u\n", en->key, en->value, en->next);
        while (en->next != ERROR_ADDR) {
            en = &g_items[en->next];
            printf("key:%u;value:%u; next:%u\n", en->key, en->value, en->next);
        }
    }
    return 0;
}



int main() {
    load();
    print();
    return 0;
}
