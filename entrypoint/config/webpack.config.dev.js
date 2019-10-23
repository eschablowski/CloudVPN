const merge = require("webpack-merge");
const defaultConfig = require("./webpack.config");
module.exports = async function(){
    return merge.smart(await defaultConfig(), {
        mode: "development"
    })
}