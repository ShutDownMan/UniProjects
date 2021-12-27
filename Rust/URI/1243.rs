use std::io;
use std::convert::TryInto;

fn validate_word(text: &String) -> Option<String> {
    let text = if text.ends_with(".") {
        text[..text.len() - 1].to_string()
    } else {
        text.to_string()
    };

    let is_word = text.len() > 0 && !text.chars()
        .any(|w| { !w.is_alphabetic() });

    if is_word {
        Some(text)
    } else {
        None
    }
}

fn get_code_level(text: &String) -> u32 {
    let words_lens = text
        .split_whitespace()
        .filter_map(|w| {

            if let Some(validate_word) = validate_word(&w.to_string()) {
                Some(validate_word.len())
            } else {
                None
            }
        })
        .collect::<Vec<usize>>();
    let avg_len: f32 = (words_lens.iter().sum::<usize>() as f32 / words_lens.len() as f32).try_into().unwrap();

    // println!("{:?}", words_lens);
    // println!("{:?}", avg_len);

    match avg_len {
        _ if avg_len <= 3.5 => { 250 },
        _ if avg_len <= 5.0 => { 500 },
        _ if avg_len >= 6.0 => { 1000 },
        _ => { 250 }
    }
}

fn main() {
    let mut continue_loop = true;

    while continue_loop {
        let mut current_line = String::new();
        let byte_count = io::stdin()
            .read_line(&mut current_line)
            .unwrap();

        if byte_count > 0 {
            println!("{}", get_code_level(&current_line))
        } else {
            continue_loop = false;
        }

    }
}