if tup.getconfig("NO_FASM") ~= "" then return end
tup.rule("WinXP_Classic_green.asm", 'fasm "%f" "%o" ' .. tup.getconfig("KPACK_CMD"), "WinXP Classic green.skn")
