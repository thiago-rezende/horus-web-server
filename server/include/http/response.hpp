/**
 * @file response.hpp
 * @author Thiago Rezende (horus.he4rt@gmail.com)
 * @brief HTTP response
 * @version 0.1
 * @date 2021-06-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once

#include <string>
#include <vector>

#include "http/common.hpp"

namespace horus
{
    namespace http
    {
        struct response
        {
            std::string version;
            uint16_t status;
            std::string reason;
            std::vector<header> headers;
            std::string body;

            std::string to_string()
            {
                std::stringstream req_str;

                req_str << version << " " << status << " " << reason << "\r\n";

                for (auto &h : headers)
                    req_str << h.name << ": " << h.value << "\r\n";

                req_str << "\r\n"
                        << body;

                return req_str.str();
            }

            std::string status_line()
            {
                return version + " " + std::to_string(status) + " " + reason;
            }
        };

        namespace stock
        {
            struct response_ok : response
            {
                response_ok()
                {
                    version = strings::version::HTTP_1_1;
                    status = static_cast<uint16_t>(status::code::ok);
                    reason = status::reason::ok;
                    body = R"(
                        <html>
                            <head>
                                <title>It Works!</title>
                                <style>
                                    html,body,div,span,applet,object,iframe,h1,h2,h3,h4,h5,h6,p,blockquote,pre,a,abbr,acronym,address,big,cite,code,del,dfn,em,img,ins,kbd,q,s,samp,small,strike,strong,sub,sup,tt,var,b,u,i,center,dl,dt,dd,ol,ul,li,fieldset,form,label,legend,table,caption,tbody,tfoot,thead,tr,th,td,article,aside,canvas,details,embed,figure,figcaption,footer,header,hgroup,menu,nav,output,ruby,section,summary,time,mark,audio,video{margin:0;padding:0;border:0;font-size:100%;font:inherit;vertical-align:baseline}article,aside,details,figcaption,figure,footer,header,hgroup,menu,nav,section{display:block}body{line-height:1}ol,ul{list-style:none}blockquote,q{quotes:none}blockquote:before,blockquote:after,q:before,q:after{content:'';content:none}table{border-collapse:collapse;border-spacing:0}
                                    html {
                                        font-family: monospace;
                                        font-size: 2.5rem;
                                        background-color: #181a1b;
                                        color: #e8e6e3;
                                    }
                                    body {
                                        display: grid;
                                        place-items: center;
                                        height: 100vh;
                                        width: 100vw;
                                    }
                                </style>
                            </head>
                            <body>
                                <h1>200 | It Works!</h1>
                            </body>
                        </html>
                    )";

                    headers.push_back(header{"Content-Type", "text/html"});
                    headers.push_back(header{"Content-Size", std::to_string(body.size())});
                }
            };

            struct response_bad_request : response
            {
                response_bad_request()
                {
                    version = strings::version::HTTP_1_1;
                    status = static_cast<uint16_t>(status::code::bad_request);
                    reason = status::reason::bad_request;
                    body = R"(
                        <html>
                            <head>
                                <title>Bad Request!</title>
                                <style>
                                    html,body,div,span,applet,object,iframe,h1,h2,h3,h4,h5,h6,p,blockquote,pre,a,abbr,acronym,address,big,cite,code,del,dfn,em,img,ins,kbd,q,s,samp,small,strike,strong,sub,sup,tt,var,b,u,i,center,dl,dt,dd,ol,ul,li,fieldset,form,label,legend,table,caption,tbody,tfoot,thead,tr,th,td,article,aside,canvas,details,embed,figure,figcaption,footer,header,hgroup,menu,nav,output,ruby,section,summary,time,mark,audio,video{margin:0;padding:0;border:0;font-size:100%;font:inherit;vertical-align:baseline}article,aside,details,figcaption,figure,footer,header,hgroup,menu,nav,section{display:block}body{line-height:1}ol,ul{list-style:none}blockquote,q{quotes:none}blockquote:before,blockquote:after,q:before,q:after{content:'';content:none}table{border-collapse:collapse;border-spacing:0}
                                    html {
                                        font-family: monospace;
                                        font-size: 2.5rem;
                                        background-color: #181a1b;
                                        color: #e8e6e3;
                                    }
                                    body {
                                        display: grid;
                                        place-items: center;
                                        height: 100vh;
                                        width: 100vw;
                                    }
                                </style>
                            </head>
                            <body>
                                <h1>400 | Bad Request!</h1>
                            </body>
                        </html>
                    )";

                    headers.push_back(header{"Content-Type", "text/html"});
                    headers.push_back(header{"Content-Size", std::to_string(body.size())});
                }
            };

            struct response_not_found : response
            {
                response_not_found()
                {
                    version = strings::version::HTTP_1_1;
                    status = static_cast<uint16_t>(status::code::not_found);
                    reason = status::reason::not_found;
                    body = R"(
                        <html>
                            <head>
                                <title>Not Found!</title>
                                <style>
                                    html,body,div,span,applet,object,iframe,h1,h2,h3,h4,h5,h6,p,blockquote,pre,a,abbr,acronym,address,big,cite,code,del,dfn,em,img,ins,kbd,q,s,samp,small,strike,strong,sub,sup,tt,var,b,u,i,center,dl,dt,dd,ol,ul,li,fieldset,form,label,legend,table,caption,tbody,tfoot,thead,tr,th,td,article,aside,canvas,details,embed,figure,figcaption,footer,header,hgroup,menu,nav,output,ruby,section,summary,time,mark,audio,video{margin:0;padding:0;border:0;font-size:100%;font:inherit;vertical-align:baseline}article,aside,details,figcaption,figure,footer,header,hgroup,menu,nav,section{display:block}body{line-height:1}ol,ul{list-style:none}blockquote,q{quotes:none}blockquote:before,blockquote:after,q:before,q:after{content:'';content:none}table{border-collapse:collapse;border-spacing:0}
                                    html {
                                        font-family: monospace;
                                        font-size: 2.5rem;
                                        background-color: #181a1b;
                                        color: #e8e6e3;
                                    }
                                    body {
                                        display: grid;
                                        place-items: center;
                                        height: 100vh;
                                        width: 100vw;
                                    }
                                </style>
                            </head>
                            <body>
                                <h1>404 | Not Found!</h1>
                            </body>
                        </html>
                    )";

                    headers.push_back(header{"Content-Type", "text/html"});
                    headers.push_back(header{"Content-Size", std::to_string(body.size())});
                }
            };

            struct response_not_implemented : response
            {
                response_not_implemented()
                {
                    version = strings::version::HTTP_1_1;
                    status = static_cast<uint16_t>(status::code::not_implemented);
                    reason = status::reason::not_implemented;
                    body = R"(
                        <html>
                            <head>
                                <title>Not Implemented!</title>
                                <style>
                                    html,body,div,span,applet,object,iframe,h1,h2,h3,h4,h5,h6,p,blockquote,pre,a,abbr,acronym,address,big,cite,code,del,dfn,em,img,ins,kbd,q,s,samp,small,strike,strong,sub,sup,tt,var,b,u,i,center,dl,dt,dd,ol,ul,li,fieldset,form,label,legend,table,caption,tbody,tfoot,thead,tr,th,td,article,aside,canvas,details,embed,figure,figcaption,footer,header,hgroup,menu,nav,output,ruby,section,summary,time,mark,audio,video{margin:0;padding:0;border:0;font-size:100%;font:inherit;vertical-align:baseline}article,aside,details,figcaption,figure,footer,header,hgroup,menu,nav,section{display:block}body{line-height:1}ol,ul{list-style:none}blockquote,q{quotes:none}blockquote:before,blockquote:after,q:before,q:after{content:'';content:none}table{border-collapse:collapse;border-spacing:0}
                                    html {
                                        font-family: monospace;
                                        font-size: 2.5rem;
                                        background-color: #181a1b;
                                        color: #e8e6e3;
                                    }
                                    body {
                                        display: grid;
                                        place-items: center;
                                        height: 100vh;
                                        width: 100vw;
                                    }
                                </style>
                            </head>
                            <body>
                                <h1>501 | Not Implemented!</h1>
                            </body>
                        </html>
                    )";

                    headers.push_back(header{"Content-Type", "text/html"});
                    headers.push_back(header{"Content-Size", std::to_string(body.size())});
                }
            };
        } // namespace stock

    } // namespace http

} // namespace horus
