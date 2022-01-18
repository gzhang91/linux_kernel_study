// struct note

#define NULL (void*)0

struct list_head {
  struct list_head *next;
  struct list_head *prev;
};

struct fox {
  unsigned long     tail_length;
  unsigned long     weight;
  int               is_fantastic;
  struct list_head  list;
};

#define container_of(ptr, type, member) ({            \
  const typeof( ((type *)0)->member ) *_mptr = (ptr); \
  (type *)( (char *)_mptr - offsetof(type, member) );})
  
#define list_entry(ptr, type, member) \
  container_of(ptr, type, member)
  
void iterator_list() {
  struct list_head *p;
  struct fox *f;
  
  list_for_each(p, &fox_list) {
    f = list_entry(p, struct fox, list);
  }
}

static struct inotify_watch *inode_find_handle(struct inode *inode,
  struct inotify_handle *ih) {
  struct inotify_watch *watch;
  
  list_for_each_entry(watch, &inode->inotify_watches, i_list) {
    if (watch->ih == ih) 
      return watch;
  }
}
  
int main(void) {
   //struct fox f1;
   //f1.tail_length = 1;
   //f1.weight = 1;
   //f1.is_fantastic = 1;
   //f1.list.next = NULL;
   //f1.list.prev = &f1.list;
   
   //struct fox f2;
   //f2.tail_length = 2;
   //f2.weight = 2;
   //f2.is_fantastic = 2;
   //f2.list.next = &f1.list;
   //f2.list.prev = &f2.list;
   //f1.list.prev = &f2.list;
   
   //list_entry(&f2.list, struct fox, list);
   
   struct fox *red_fox;
   red_fox = kmalloc(sizeof(*red_fox), GFP_KERNEL);
   red_fox->tail_length = 40;
   red_fox->weight = 6;
   red_fox->is_fantastic = 0;
   INIT_LIST_HEAD(&red_fox->list);
   
   //struct fox red_fox = {
   // .tail_length = 40,
   // .weight = 6,
   // .list = LIST_HEAD_INIT(red_fox.list),
   //};
  
  return 0;
}