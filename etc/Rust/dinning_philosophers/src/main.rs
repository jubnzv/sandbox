use std::sync::{Arc, Mutex};
use std::thread;
use std::time::Duration;

struct Philosopher {
    name: String,
    left: usize,
    right: usize,
}

impl Philosopher {
    fn new(name: &str, left: usize, right: usize) -> Philosopher {
        Philosopher {
            name: name.to_string(),
            left: left,
            right: right,
        }
    }

    fn eat(&self, table: &Table) {
        let _left = table.forks[self.left].lock().unwrap();
        thread::sleep(Duration::from_millis(150));
        let _right = table.forks[self.right].lock().unwrap();

        println!("{} starts eat", self.name);

        thread::sleep(Duration::from_millis(1000));

        println!("{} ends eat", self.name)
    }
}

struct Table {
    forks: Vec<Mutex<()>>,
}

fn main() {
    let table = Arc::new(Table {
        forks: vec![
            Mutex::new(()),
            Mutex::new(()),
            Mutex::new(()),
            Mutex::new(()),
            Mutex::new(()),
        ],
    });

    let philosophers = vec![
        Philosopher::new("First", 0, 1),
        Philosopher::new("Second", 1, 2),
        Philosopher::new("Third", 2, 3),
        Philosopher::new("Fourth", 3, 4),
        Philosopher::new("Fifth", 0, 4),
    ];

    let handles: Vec<_> = philosophers
        .into_iter()
        .map(|p| {
            let table = table.clone();

            thread::spawn(move || {
                p.eat(&table);
            })
        })
        .collect();

    for h in handles {
        h.join().unwrap();
    }
}
