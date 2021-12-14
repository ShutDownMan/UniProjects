use std::io;

fn read_numbers() -> (String, String) {
    let mut input_text = String::new();
    io::stdin()
        .read_line(&mut input_text)
        .expect("failed to read from stdin");
    
    let values = input_text.split_whitespace()
        .map(|s| {
            s.trim().to_string()
        })
        .collect::<Vec<String>>();

    let (first_num, second_num) = match &values[..] {
        [first, second, ..] => (first.to_string(), second.to_string()),
        _ => unreachable!(),
    };

    (first_num, second_num)
}

fn main() {
    let mut continue_loop = true;

    while continue_loop {
        let (d, n) = read_numbers();

        if d != "0" {
            let d_chr = d.chars().next().unwrap();
            let stripped_str: String = n.chars()
                .filter(|n_chr| {
                    *n_chr != d_chr
                })
                .collect::<String>()
                .trim_start_matches('0')
                .to_string();
            match stripped_str.as_ref() {
                "" => println!("0"),
                _ => println!("{}", stripped_str)
            }
            
        } else {
            continue_loop = false;
        }
    }
}