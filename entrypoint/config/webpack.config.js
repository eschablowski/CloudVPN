const paths = require("./paths");
const webpack = require("webpack");
const nodeExternals = require('webpack-node-externals');

module.exports = async function () {
    return {
        target: "node",
        devtool: "source-map",
        entry: {
            main: paths.serverIndex
        },
        output: {
            filename: "[name].js",
            path: paths.output,
            chunkFilename: '[id].js'
        },
        resolve: {
            extensions: [".ts", ".js"]
        },
        module: {
            rules: [
                {
                    test: /\.(js|ts)$/,
                    use: ["source-map-loader"],
                    enforce: "pre"
                },
                {
                    test: /\.(js|ts)$/,
                    exclude: /node_modules/,
                    use: ["eslint-loader"],
                    enforce: "pre"
                },
                {
                    test: /\.node$/,
                    use: 'node-loader'
                },
                {
                    test: /\.ts?$/,
                    use: 'ts-loader',
                    exclude: /node_modules/,
                },
            ]
        },
        plugins: [
            new webpack.BannerPlugin({
                banner: "require('source-map-support').install();",
                raw: true
            })
        ],
        externals: [
            nodeExternals(),
            nodeExternals({
                modulesDir: "../node_modules"
            })]
    }
}