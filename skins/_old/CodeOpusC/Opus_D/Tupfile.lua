if tup.getconfig("NO_FASM") ~= "" then return end
tup.rule("Opus_D.asm", 'fasm "%f" "%o" ' .. tup.getconfig("KPACK_CMD"), "Opus_D.skn")
