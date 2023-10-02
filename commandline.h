#ifndef COMMANDLINE_H_
#define COMMANDLINE_H_

// Bitband aliases
#define RED_LED      (*((volatile uint32_t *)(0x42000000 + (0x400253FC-0x40000000)*32 + 1*4)))
#define GREEN_LED    (*((volatile uint32_t *)(0x42000000 + (0x400253FC-0x40000000)*32 + 3*4)))

// PortF masks
#define GREEN_LED_MASK 8
#define RED_LED_MASK 2


#define MAX_CHARS   80u
#define MAX_FIELDS  5u


typedef struct _USER_DATA
{
    char buffer[MAX_CHARS + 1];
    uint8_t fieldPosition[MAX_FIELDS];
    char fieldType[MAX_FIELDS];
    uint8_t fieldCount;
} USER_DATA;

void ps(void);
void ipcs(void);
void kill(const uint32_t pid);
void pkill(const char *proc_name);
void preempt(bool onOff);
void sched(bool rrOrPrio);
void pidof(const char *proc_name);
void run(const char *proc_name);
void processCommands(USER_DATA *info);

#endif 
