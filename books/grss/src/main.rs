use std::path::PathBuf;

use clap::Parser;

#[derive(Debug, Parser)]
struct Cli {
    pattern: String,
    #[clap(parse(from_os_str))]
    path: PathBuf,
}

fn main() {
    let args = Cli::parse();
    println!("{:?}", args);
}
