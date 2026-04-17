use pyo3::prelude::*;

#[pymodule]
fn rloop(_py: Python, m: &PyModule) -> PyResult<()> {
    use pyo3::prelude::*;

    #[pyfn(m)]
    fn rust_loop() -> PyResult<String> {
        let start = std::time::Instant::now();
        for i in 0..=1000_000_000 {
            if i % 100_000_000 == 0 {
                println!("i = {}", i);
            }
        }
        // println!("Elapsed: {:.2?}", start.elapsed());
        Ok(format!("Elapsed (Rust): {:.2?}", start.elapsed()))
    }
    Ok(())
}
