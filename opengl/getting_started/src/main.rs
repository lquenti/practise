use glfw::Context;

const WIDTH: u32 = 800;
const HEIGHT: u32 = 600;
const TITLE: &str = "Hello Title";

fn main() {
    let mut glfw = glfw::init_no_callbacks().unwrap();
    glfw.window_hint(glfw::WindowHint::ContextVersion(3, 3));
    glfw.window_hint(glfw::WindowHint::OpenGlProfile(glfw::OpenGlProfileHint::Core));
    #[cfg(target_os = "macos")]
    glfw.window_hint(glfw::WindowHint::OpenGlForwardCompat(true));

    let (mut window, events) = glfw.create_window(
        WIDTH,
        HEIGHT,
        TITLE,
        glfw::WindowMode::Windowed
    ).expect("Failed to create GLFW window");

    window.make_current();
    window.set_key_polling(true);
    window.set_framebuffer_size_polling(true);

    // load all openGL function pointers
    gl::load_with(|symbol| window.get_proc_address(symbol) as *const _);
    window.set_framebuffer_size_callback(|&mut _, width, height|
        unsafe {
            gl::Viewport(0, 0, width, height);
        }
    );

    let mut r = 1.0;
    while !window.should_close() {
        if window.get_key(glfw::Key::Escape) == glfw::Action::Press {
            window.set_should_close(true);
        }

        unsafe {
            gl::ClearColor(r, 0.0, 0.0, 1.0);
            gl::Clear(gl::COLOR_BUFFER_BIT);
        }
        r += 0.02;
        r %= 1.0;

        window.swap_buffers();
        glfw.poll_events();
    }

}
