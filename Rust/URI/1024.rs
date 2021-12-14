use std::io;
use std::num::ParseIntError;
use std::convert::TryInto;

fn read_int() -> Result<i32, ParseIntError> {
    let mut input_text = String::new();
    io::stdin()
        .read_line(&mut input_text)
        .expect("failed to read from stdin");

    input_text.trim().parse::<i32>()
}

// Na primeira passada, somente caracteres que sejam letras minúsculas e maiúsculas devem ser deslocadas 3 posições para a direita,
// Na segunda passada, a linha deverá ser invertida.
// Na terceira e última passada, todo caractere a partir da metade em diante devem ser deslocados para a esquerda

fn shift_right_char(c: char, pos: i32) -> char {
    std::char::from_u32((c as i32 + pos).try_into().unwrap()).unwrap_or(c)
}

fn crypt(text: &String) -> String {
    let mut encrypted_text: String = text.clone();

    encrypted_text = encrypted_text.chars()
        .map(|c| {
            if c.is_alphabetic() {
                shift_right_char(c, 3)
            } else {
                c
            }
        })
        .collect::<String>();
    
    encrypted_text = encrypted_text.chars()
        .rev()
        .collect::<String>();

    let midway_ind: usize = (encrypted_text.len() / 2).try_into().unwrap();
    let left_trunc: String = encrypted_text[..midway_ind].to_string();
    let mut right_trunc: String = encrypted_text[midway_ind..].to_string();

    right_trunc = right_trunc.chars()
        .map(|c| {shift_right_char(c, -1)})
        .collect::<String>();

    encrypted_text = left_trunc.to_string();
    encrypted_text.push_str(&right_trunc);

    encrypted_text
}

fn main() {
    let quant_lines = read_int().unwrap();

    for _ in 0..quant_lines {
        let mut current_line = String::new();
        io::stdin()
            .read_line(&mut current_line)
            .unwrap();
        
        current_line = current_line.trim().to_string();

        println!("{}", crypt(&current_line));

    }
}