require 'mkmf'

ok = true
hdr = nil
case
when macro_defined?("_WIN32", "")
  # rb_w32_map_errno: 1.8.7
  vk_header = ($nmake == ?m ? "{$(srcdir)}" : "") << "win32_vk.chksum"
when hdr = %w"termios.h termio.h".find {|h| have_header(h)}
  have_func("cfmakeraw", hdr)
when have_header(hdr = "sgtty.h")
  %w"stty gtty".each {|f| have_func(f, hdr)}
else
  ok = false
end
if ok
  have_header("sys/ioctl.h") if hdr
  # rb_check_hash_type: 1.9.3
  # rb_io_get_write_io: 1.9.1
  # rb_cloexec_open: 2.0.0
  $defs << "-D""ENABLE_IO_GETPASS=1"
  create_makefile("io/console") {|conf|
    conf << "\n""VK_HEADER = #{vk_header}\n"
  }
end
