const { resolve } = require("path");

const appDir = resolve(__dirname, "..")

module.exports = {
    src: resolve(appDir, "src"),
    serverIndex: resolve(appDir, "src", "index.ts"),
    output: resolve(appDir, "build"),
    getSrc: (...p) => resolve(appDir, "src", ...p)
}