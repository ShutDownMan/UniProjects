use std::io;
use std::num::ParseIntError;

fn read_int() -> Result<i32, ParseIntError> {
    let mut input_text = String::new();
    io::stdin()
        .read_line(&mut input_text)
        .expect("failed to read from stdin");

    let trimmed = input_text.trim();
    trimmed.parse::<i32>()
}

fn main() {
    let line_count = read_int().unwrap();

    for _ in 0..line_count {
        let current_number = read_int().unwrap();
        let mut current_result_str = String::new();

        if current_number == 0 {
            current_result_str.push_str("NULL");
        } else {
            if current_number%2 == 0 {
                current_result_str.push_str("EVEN")
            } else {
                current_result_str.push_str("ODD")
            }

            if current_number > 0 {
                current_result_str.push_str(" POSITIVE")
            } else {
                current_result_str.push_str(" NEGATIVE")
            }
        }

        println!("{}", current_result_str)
    }
}