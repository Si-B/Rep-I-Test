<?xml version="1.0" encoding="UTF-8"?>
<!--Erstellt und generiert von Altova StyleVision Enterprise Edition 2012 rel. 2 (x64) - nähere Informationen siehe http://www.altova.com/de/stylevision-->
<xsl:stylesheet version="2.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:altova="http://www.altova.com" xmlns:altovaext="http://www.altova.com/xslt-extensions" xmlns:clitype="clitype" xmlns:fn="http://www.w3.org/2005/xpath-functions" xmlns:iso4217="http://www.xbrl.org/2003/iso4217" xmlns:ix="http://www.xbrl.org/2008/inlineXBRL" xmlns:java="java" xmlns:link="http://www.xbrl.org/2003/linkbase" xmlns:sps="http://www.altova.com/StyleVision/user-xpath-functions" xmlns:xbrldi="http://xbrl.org/2006/xbrldi" xmlns:xbrli="http://www.xbrl.org/2003/instance" xmlns:xlink="http://www.w3.org/1999/xlink" xmlns:xs="http://www.w3.org/2001/XMLSchema" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:fo="http://www.w3.org/1999/XSL/Format" xmlns:svg="http://www.w3.org/2000/svg" exclude-result-prefixes="#all">
	<xsl:output version="1.0" method="xml" encoding="UTF-8" indent="no"/>
	<xsl:param name="altova:bGeneratingFromPxf" select="false()"/>
	<xsl:param name="SV_OutputFormat" select="'PDF'"/>
	<xsl:param name="SV_BaseOutputFileName" as="xs:string?">
		<xsl:sequence select="for $i in altovaext:get-base-output-uri(), $j in tokenize( $i, &apos;[/\\]&apos; )[last()] return replace( $j, &apos;\.[^\.\s#%;]*$&apos;, &apos;&apos; )" use-when="function-available(&apos;altovaext:get-base-output-uri&apos;)"/>
	</xsl:param>
	<xsl:param name="SV_GeneratedFileNamePrefix" select="if ( $SV_BaseOutputFileName ) then $SV_BaseOutputFileName else &apos;WaffentabelleBestand&apos;" as="xs:string?"/>
	<xsl:variable name="XML" select="/"/>
	<xsl:variable name="fo:layout-master-set">
		<fo:layout-master-set>
			<fo:simple-page-master master-name="page-master-94110848-even" margin-left="0.79in" margin-right="0.79in" page-height="8.27in" page-width="11.69in" margin-top="0.30in" margin-bottom="0.30in">
				<fo:region-body margin-top="0.30in" margin-bottom="0.30in" column-count="1" column-gap="0.50in"/>
				<fo:region-before region-name="even-page-header" overflow="hidden" extent="0.30in"/>
				<fo:region-after region-name="even-page-footer" overflow="hidden" extent="0.30in"/>
			</fo:simple-page-master>
			<fo:simple-page-master master-name="page-master-94110848-odd" margin-left="0.79in" margin-right="0.79in" page-height="8.27in" page-width="11.69in" margin-top="0.30in" margin-bottom="0.30in">
				<fo:region-body margin-top="0.30in" margin-bottom="0.30in" column-count="1" column-gap="0.50in"/>
				<fo:region-before region-name="odd-page-header" overflow="hidden" extent="0.30in"/>
				<fo:region-after region-name="odd-page-footer" overflow="hidden" extent="0.30in"/>
			</fo:simple-page-master>
			<fo:page-sequence-master master-name="page-master-94110848">
				<fo:repeatable-page-master-alternatives>
					<fo:conditional-page-master-reference master-reference="page-master-94110848-even" odd-or-even="even"/>
					<fo:conditional-page-master-reference master-reference="page-master-94110848-odd" odd-or-even="odd"/>
				</fo:repeatable-page-master-alternatives>
			</fo:page-sequence-master>
		</fo:layout-master-set>
	</xsl:variable>
	<xsl:variable name="altova:nPxPerIn" select="96"/>
	<xsl:variable name="altova:CssImages" select="()"/>
	<xsl:variable name="altova:sCssSwitch" as="xs:string" select="''"/>
	<xsl:variable name="altova:nodeCssClasses" select="()"/>
	<xsl:variable name="altova:design-xslt-tree-view">
		<altova:main-document url="{if ($SV_BaseOutputFileName) then concat($SV_BaseOutputFileName,'.fo') else ''}">
			<fo:root>
				<xsl:copy-of select="$fo:layout-master-set"/>
				<fo:page-sequence master-reference="page-master-94110848" initial-page-number="auto" format="1" force-page-count="no-force">
					<fo:static-content flow-name="odd-page-header">
						<fo:block-container overflow="hidden" display-align="before">
							<fo:block font-family="Cordia New">
								<xsl:variable name="altova:table">
									<fo:table font-family="Courier" width="100%" table-layout="fixed" border-spacing="2pt">
										<fo:table-column column-width="80%"/>
										<fo:table-column column-width="20%"/>
										<xsl:variable name="altova:CurrContextGrid_0" select="."/>
										<xsl:variable name="altova:ColumnData">
											<altova:Internal/>
										</xsl:variable>
										<fo:table-body start-indent="0pt">
											<fo:table-row>
												<fo:table-cell font-size="10pt" padding="0" display-align="center">
													<fo:block-container overflow="hidden">
														<fo:block text-align="left">
															<fo:inline font-weight="bold">
																<xsl:text>Waffenbestand zum 1. </xsl:text>
															</fo:inline>
															<xsl:for-each select="$XML">
																<xsl:for-each select="waffen">
																	<xsl:for-each select="@datum">
																		<fo:inline>
																			<xsl:value-of select="string(.)"/>
																		</fo:inline>
																	</xsl:for-each>
																</xsl:for-each>
															</xsl:for-each>
														</fo:block>
													</fo:block-container>
												</fo:table-cell>
												<fo:table-cell font-size="10pt" padding="0" display-align="center">
													<fo:block-container overflow="hidden">
														<fo:block text-align="right">
															<fo:inline font-weight="bold">
																<xsl:text>Seite: </xsl:text>
															</fo:inline>
															<fo:page-number/>
															<fo:inline>
																<xsl:text> von </xsl:text>
															</fo:inline>
															<fo:page-number-citation ref-id="SV_RefID_PageTotal"/>
															<fo:inline>
																<xsl:text>&#160;</xsl:text>
															</fo:inline>
														</fo:block>
													</fo:block-container>
												</fo:table-cell>
											</fo:table-row>
										</fo:table-body>
									</fo:table>
								</xsl:variable>
								<xsl:apply-templates select="$altova:table" mode="altova:copy-table"/>
							</fo:block>
						</fo:block-container>
					</fo:static-content>
					<fo:static-content flow-name="even-page-header">
						<fo:block-container overflow="hidden" display-align="before">
							<fo:block font-family="Cordia New">
								<xsl:variable name="altova:table">
									<fo:table font-family="Courier" width="100%" table-layout="fixed" border-spacing="2pt">
										<fo:table-column column-width="80%"/>
										<fo:table-column column-width="20%"/>
										<xsl:variable name="altova:CurrContextGrid_0" select="."/>
										<xsl:variable name="altova:ColumnData">
											<altova:Internal/>
										</xsl:variable>
										<fo:table-body start-indent="0pt">
											<fo:table-row>
												<fo:table-cell font-size="10pt" padding="0" display-align="center">
													<fo:block-container overflow="hidden">
														<fo:block text-align="left">
															<fo:inline font-weight="bold">
																<xsl:text>Waffenbestand zum 1. </xsl:text>
															</fo:inline>
															<xsl:for-each select="$XML">
																<xsl:for-each select="waffen">
																	<xsl:for-each select="@datum">
																		<fo:inline>
																			<xsl:value-of select="string(.)"/>
																		</fo:inline>
																	</xsl:for-each>
																</xsl:for-each>
															</xsl:for-each>
														</fo:block>
													</fo:block-container>
												</fo:table-cell>
												<fo:table-cell font-size="10pt" padding="0" display-align="center">
													<fo:block-container overflow="hidden">
														<fo:block text-align="right">
															<fo:inline font-weight="bold">
																<xsl:text>Seite: </xsl:text>
															</fo:inline>
															<fo:page-number/>
															<fo:inline>
																<xsl:text> von </xsl:text>
															</fo:inline>
															<fo:page-number-citation ref-id="SV_RefID_PageTotal"/>
															<fo:inline>
																<xsl:text>&#160;</xsl:text>
															</fo:inline>
														</fo:block>
													</fo:block-container>
												</fo:table-cell>
											</fo:table-row>
										</fo:table-body>
									</fo:table>
								</xsl:variable>
								<xsl:apply-templates select="$altova:table" mode="altova:copy-table"/>
							</fo:block>
						</fo:block-container>
					</fo:static-content>
					<fo:static-content flow-name="odd-page-footer">
						<fo:block-container height="0.30in" overflow="hidden" display-align="after">
							<fo:block font-family="Cordia New">
								<xsl:variable name="altova:table">
									<fo:table font-family="Courier" width="100%" table-layout="fixed" border-spacing="2pt">
										<fo:table-column column-width="90%"/>
										<fo:table-column column-width="10%"/>
										<xsl:variable name="altova:CurrContextGrid_1" select="."/>
										<xsl:variable name="altova:ColumnData">
											<altova:Internal/>
										</xsl:variable>
										<fo:table-body start-indent="0pt">
											<fo:table-row>
												<fo:table-cell number-columns-spanned="2" font-size="4pt" padding="0" display-align="center">
													<fo:block-container overflow="hidden">
														<fo:block text-align="left">
															<fo:block text-align="center">
																<fo:leader leader-pattern="rule" rule-thickness="1" leader-length="100%" color="black"/>
															</fo:block>
														</fo:block>
													</fo:block-container>
												</fo:table-cell>
											</fo:table-row>
											<fo:table-row>
												<fo:table-cell font-size="4pt" padding="0" display-align="center">
													<fo:block-container overflow="hidden">
														<fo:block text-align="left">
															<fo:inline>
																<xsl:text>Condition Waffenhandelsbuch</xsl:text>
															</fo:inline>
														</fo:block>
													</fo:block-container>
												</fo:table-cell>
												<fo:table-cell font-size="10pt" padding="0" display-align="center">
													<fo:block-container overflow="hidden">
														<fo:block text-align="right"/>
													</fo:block-container>
												</fo:table-cell>
											</fo:table-row>
										</fo:table-body>
									</fo:table>
								</xsl:variable>
								<xsl:apply-templates select="$altova:table" mode="altova:copy-table"/>
							</fo:block>
						</fo:block-container>
					</fo:static-content>
					<fo:static-content flow-name="even-page-footer">
						<fo:block-container height="0.30in" overflow="hidden" display-align="after">
							<fo:block font-family="Cordia New">
								<xsl:variable name="altova:table">
									<fo:table font-family="Courier" width="100%" table-layout="fixed" border-spacing="2pt">
										<fo:table-column column-width="90%"/>
										<fo:table-column column-width="10%"/>
										<xsl:variable name="altova:CurrContextGrid_1" select="."/>
										<xsl:variable name="altova:ColumnData">
											<altova:Internal/>
										</xsl:variable>
										<fo:table-body start-indent="0pt">
											<fo:table-row>
												<fo:table-cell number-columns-spanned="2" font-size="4pt" padding="0" display-align="center">
													<fo:block-container overflow="hidden">
														<fo:block text-align="left">
															<fo:block text-align="center">
																<fo:leader leader-pattern="rule" rule-thickness="1" leader-length="100%" color="black"/>
															</fo:block>
														</fo:block>
													</fo:block-container>
												</fo:table-cell>
											</fo:table-row>
											<fo:table-row>
												<fo:table-cell font-size="4pt" padding="0" display-align="center">
													<fo:block-container overflow="hidden">
														<fo:block text-align="left">
															<fo:inline>
																<xsl:text>Condition Waffenhandelsbuch</xsl:text>
															</fo:inline>
														</fo:block>
													</fo:block-container>
												</fo:table-cell>
												<fo:table-cell font-size="10pt" padding="0" display-align="center">
													<fo:block-container overflow="hidden">
														<fo:block text-align="right"/>
													</fo:block-container>
												</fo:table-cell>
											</fo:table-row>
										</fo:table-body>
									</fo:table>
								</xsl:variable>
								<xsl:apply-templates select="$altova:table" mode="altova:copy-table"/>
							</fo:block>
						</fo:block-container>
					</fo:static-content>
					<fo:flow flow-name="xsl-region-body">
						<fo:block font-family="Cordia New">
							<xsl:variable name="altova:table">
								<fo:table font-family="Courier" text-align="center" table-layout="fixed" width="100%" border-spacing="2pt">
									<fo:table-column column-width="13mm"/>
									<fo:table-column column-width="20mm"/>
									<fo:table-column column-width="proportional-column-width(1)"/>
									<fo:table-column column-width="proportional-column-width(1)"/>
									<fo:table-column column-width="proportional-column-width(1)"/>
									<fo:table-column column-width="proportional-column-width(1)"/>
									<fo:table-column column-width="proportional-column-width(1)"/>
									<xsl:variable name="altova:CurrContextGrid_2" select="."/>
									<xsl:variable name="altova:ColumnData">
										<altova:Internal/>
									</xsl:variable>
									<fo:table-header background-color="#d2d2d2" font-size="5pt" font-weight="bold" white-space-collapse="false" linefeed-treatment="preserve" wrap-option="wrap" white-space-treatment="ignore-if-surrounding-linefeed" start-indent="0pt">
										<fo:table-row height="auto">
											<fo:table-cell border-bottom-style="solid" border-bottom-width="thin" font-size="8pt" padding-bottom="0.01in" padding-left="0.02in" padding-right="0.02in" padding-top="0.01in" white-space-collapse="false" linefeed-treatment="preserve" wrap-option="wrap" white-space-treatment="ignore-if-surrounding-linefeed" padding="2pt" display-align="center">
												<fo:block-container overflow="hidden">
													<fo:block text-align="center">
														<fo:inline text-align="center">
															<xsl:text>Lfd. Nummer</xsl:text>
														</fo:inline>
													</fo:block>
												</fo:block-container>
											</fo:table-cell>
											<fo:table-cell border-bottom-style="solid" border-bottom-width="thin" border-left-style="solid" border-left-width="thin" border-top-style="none" border-top-width="thin" font-size="8pt" padding-bottom="0.01in" padding-left="0.02in" padding-right="0.02in" padding-top="0.01in" white-space-collapse="false" linefeed-treatment="preserve" wrap-option="wrap" white-space-treatment="ignore-if-surrounding-linefeed" padding="2pt" display-align="center">
												<fo:block-container overflow="hidden">
													<fo:block text-align="center">
														<fo:inline font-family="Courier" text-align="center">
															<xsl:text>Eingang</xsl:text>
														</fo:inline>
													</fo:block>
												</fo:block-container>
											</fo:table-cell>
											<fo:table-cell border-bottom-style="solid" border-bottom-width="thin" border-left-style="solid" border-left-width="thin" border-top-style="none" border-top-width="thin" font-size="8pt" padding-bottom="0.01in" padding-left="0.02in" padding-right="0.02in" padding-top="0.01in" white-space-collapse="false" linefeed-treatment="preserve" wrap-option="wrap" white-space-treatment="ignore-if-surrounding-linefeed" padding="2pt" display-align="center">
												<fo:block-container overflow="hidden">
													<fo:block text-align="center">
														<fo:inline font-family="Courier" text-align="center">
															<xsl:text>Waffentyp</xsl:text>
														</fo:inline>
													</fo:block>
												</fo:block-container>
											</fo:table-cell>
											<fo:table-cell border-bottom-style="solid" border-bottom-width="thin" border-left-style="solid" border-left-width="thin" border-top-style="none" border-top-width="thin" font-size="8pt" padding-bottom="0.01in" padding-left="0.02in" padding-right="0.02in" padding-top="0.01in" white-space-collapse="false" linefeed-treatment="preserve" wrap-option="wrap" white-space-treatment="ignore-if-surrounding-linefeed" padding="2pt" display-align="center">
												<fo:block-container overflow="hidden">
													<fo:block text-align="center">
														<fo:inline font-family="Courier" text-align="center">
															<xsl:text>Hersteller</xsl:text>
														</fo:inline>
													</fo:block>
												</fo:block-container>
											</fo:table-cell>
											<fo:table-cell border-bottom-style="solid" border-bottom-width="thin" border-left-style="solid" border-left-width="thin" border-top-style="none" border-top-width="thin" font-size="8pt" padding-bottom="0.01in" padding-left="0.02in" padding-right="0.02in" padding-top="0.01in" white-space-collapse="false" linefeed-treatment="preserve" wrap-option="wrap" white-space-treatment="ignore-if-surrounding-linefeed" padding="2pt" display-align="center">
												<fo:block-container overflow="hidden">
													<fo:block text-align="center">
														<fo:inline font-family="Courier" text-align="center">
															<xsl:text>Seriennummer</xsl:text>
														</fo:inline>
													</fo:block>
												</fo:block-container>
											</fo:table-cell>
											<fo:table-cell border-bottom-style="solid" border-bottom-width="thin" border-left-style="solid" border-left-width="thin" border-top-style="none" border-top-width="thin" font-size="8pt" padding-bottom="0.01in" padding-left="0.02in" padding-right="0.02in" padding-top="0.01in" white-space-collapse="false" linefeed-treatment="preserve" wrap-option="wrap" white-space-treatment="ignore-if-surrounding-linefeed" padding="2pt" display-align="center">
												<fo:block-container overflow="hidden">
													<fo:block text-align="center">
														<fo:inline font-family="Courier" text-align="center">
															<xsl:text>Überlasser</xsl:text>
														</fo:inline>
													</fo:block>
												</fo:block-container>
											</fo:table-cell>
											<fo:table-cell border-bottom-style="solid" border-bottom-width="thin" border-left-style="solid" border-left-width="thin" border-top-style="none" border-top-width="thin" font-size="8pt" padding-bottom="0.01in" padding-left="0.02in" padding-right="0.02in" padding-top="0.01in" white-space-collapse="false" linefeed-treatment="preserve" wrap-option="wrap" white-space-treatment="ignore-if-surrounding-linefeed" padding="2pt" display-align="center">
												<fo:block-container overflow="hidden">
													<fo:block text-align="center">
														<fo:inline>
															<xsl:text>Überlasseradresse</xsl:text>
														</fo:inline>
													</fo:block>
												</fo:block-container>
											</fo:table-cell>
										</fo:table-row>
									</fo:table-header>
									<fo:table-body text-align="center" start-indent="0pt">
										<xsl:for-each select="$XML">
											<xsl:for-each select="waffen">
												<xsl:for-each select="waffe">
													<fo:table-row font-size="7pt" text-align="center" background-color="{if ( position() mod 2 = 0 ) then &quot;white&quot; else &quot;#e1e1e1&quot;}">
														<xsl:variable name="sText-decoration">
															<xsl:call-template name="altova:MakeValueAbsoluteIfPixels">
																<xsl:with-param name="sValue" select="if (waffeStatus=&quot;Inaktiv&quot;) then &quot;line-through&quot; else &quot;none&quot;"/>
															</xsl:call-template>
														</xsl:variable>
														<xsl:if test="$sText-decoration != ''">
															<xsl:attribute name="text-decoration">
																<xsl:value-of select="$sText-decoration"/>
															</xsl:attribute>
														</xsl:if>
														<fo:table-cell border-right-color="#969696" border-right-style="dotted" border-right-width="thin" font-size="7pt" keep-together.within-page="always" keep-together.within-column="always" table-omit-header-at-break="true" padding="2pt" display-align="center">
															<fo:block-container overflow="hidden">
																<fo:block text-align="center">
																	<xsl:for-each select="laufendeNummer">
																		<altova:inline-container-substitute text-align="center">
																			<xsl:apply-templates/>
																		</altova:inline-container-substitute>
																	</xsl:for-each>
																</fo:block>
															</fo:block-container>
														</fo:table-cell>
														<fo:table-cell border-right-color="#969696" border-right-style="dotted" border-right-width="thin" font-size="7pt" keep-together.within-page="always" keep-together.within-column="always" table-omit-header-at-break="true" padding="2pt" display-align="center">
															<fo:block-container overflow="hidden">
																<fo:block text-align="center">
																	<xsl:for-each select="eingang">
																		<altova:inline-container-substitute text-align="center">
																			<xsl:apply-templates/>
																		</altova:inline-container-substitute>
																	</xsl:for-each>
																</fo:block>
															</fo:block-container>
														</fo:table-cell>
														<fo:table-cell border-right-color="#969696" border-right-style="dotted" border-right-width="thin" font-size="7pt" keep-together.within-page="always" keep-together.within-column="always" table-omit-header-at-break="true" padding="2pt" display-align="center">
															<fo:block-container overflow="hidden">
																<fo:block text-align="center">
																	<xsl:for-each select="waffentypFeingliederung">
																		<xsl:call-template name="Vorlage1"/>
																	</xsl:for-each>
																</fo:block>
															</fo:block-container>
														</fo:table-cell>
														<fo:table-cell border-right-color="#969696" border-right-style="dotted" border-right-width="thin" font-size="7pt" keep-together.within-page="always" keep-together.within-column="always" table-omit-header-at-break="true" padding="2pt" display-align="center">
															<fo:block-container overflow="hidden">
																<fo:block text-align="center">
																	<xsl:for-each select="hersteller">
																		<xsl:call-template name="Vorlage1"/>
																	</xsl:for-each>
																</fo:block>
															</fo:block-container>
														</fo:table-cell>
														<fo:table-cell border-right-color="#969696" border-right-style="dotted" border-right-width="thin" font-size="7pt" keep-together.within-page="always" keep-together.within-column="always" table-omit-header-at-break="true" padding="2pt" display-align="center">
															<fo:block-container overflow="hidden">
																<fo:block text-align="center">
																	<xsl:for-each select="seriennummer1">
																		<xsl:call-template name="Vorlage1"/>
																	</xsl:for-each>
																</fo:block>
															</fo:block-container>
														</fo:table-cell>
														<fo:table-cell border-right-color="#969696" border-right-style="dotted" border-right-width="thin" font-size="7pt" keep-together.within-page="always" keep-together.within-column="always" table-omit-header-at-break="true" padding="2pt" display-align="center">
															<fo:block-container overflow="hidden">
																<fo:block text-align="center">
																	<xsl:for-each select="ueberlasser">
																		<altova:inline-container-substitute text-align="center">
																			<xsl:apply-templates/>
																		</altova:inline-container-substitute>
																	</xsl:for-each>
																</fo:block>
															</fo:block-container>
														</fo:table-cell>
														<fo:table-cell border-right-color="#969696" border-right-style="dotted" border-right-width="thin" font-size="7pt" padding="2pt" display-align="center">
															<fo:block-container overflow="hidden">
																<fo:block text-align="left">
																	<xsl:for-each select="ueberlasserAdresse">
																		<altova:inline-container-substitute text-align="center">
																			<xsl:apply-templates/>
																		</altova:inline-container-substitute>
																	</xsl:for-each>
																</fo:block>
															</fo:block-container>
														</fo:table-cell>
													</fo:table-row>
												</xsl:for-each>
											</xsl:for-each>
										</xsl:for-each>
									</fo:table-body>
								</fo:table>
							</xsl:variable>
							<xsl:apply-templates select="$altova:table" mode="altova:copy-table"/>
							<altova:line-break/>
						</fo:block>
						<fo:block id="SV_RefID_PageTotal"/>
					</fo:flow>
				</fo:page-sequence>
			</fo:root>
		</altova:main-document>
	</xsl:variable>
	<xsl:template name="Vorlage1">
		<altova:inline-container-substitute font-size="7pt" text-align="center">
			<xsl:value-of select="string-join(for $i in 1 to string-length(.) return substring(.,$i,1),codepoints-to-string(8203))"/>
		</altova:inline-container-substitute>
	</xsl:template>
	<xsl:template name="altova:double-backslash">
		<xsl:param name="text"/>
		<xsl:param name="text-length"/>
		<xsl:variable name="text-after-bs" select="substring-after($text, '\')"/>
		<xsl:variable name="text-after-bs-length" select="string-length($text-after-bs)"/>
		<xsl:choose>
			<xsl:when test="$text-after-bs-length = 0">
				<xsl:choose>
					<xsl:when test="substring($text, $text-length) = '\'">
						<xsl:value-of select="concat(substring($text,1,$text-length - 1), '\\')"/>
					</xsl:when>
					<xsl:otherwise>
						<xsl:value-of select="$text"/>
					</xsl:otherwise>
				</xsl:choose>
			</xsl:when>
			<xsl:otherwise>
				<xsl:value-of select="concat(substring($text,1,$text-length - $text-after-bs-length - 1), '\\')"/>
				<xsl:call-template name="altova:double-backslash">
					<xsl:with-param name="text" select="$text-after-bs"/>
					<xsl:with-param name="text-length" select="$text-after-bs-length"/>
				</xsl:call-template>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>
	<xsl:template name="altova:MakeValueAbsoluteIfPixels">
		<xsl:param name="sValue"/>
		<xsl:variable name="sBeforePx" select="substring-before($sValue, 'px')"/>
		<xsl:choose>
			<xsl:when test="$sBeforePx">
				<xsl:variable name="nLengthOfInteger">
					<xsl:call-template name="altova:GetCharCountOfIntegerAtEndOfString">
						<xsl:with-param name="sText" select="$sBeforePx"/>
					</xsl:call-template>
				</xsl:variable>
				<xsl:variable name="nPosOfInteger" select="string-length($sBeforePx) - $nLengthOfInteger + 1"/>
				<xsl:variable name="nValuePx" select="substring($sBeforePx, $nPosOfInteger)"/>
				<xsl:variable name="nValueIn" select="number($nValuePx) div number($altova:nPxPerIn)"/>
				<xsl:variable name="nLengthBeforeInteger" select="string-length($sBeforePx) - $nLengthOfInteger"/>
				<xsl:variable name="sRest">
					<xsl:call-template name="altova:MakeValueAbsoluteIfPixels">
						<xsl:with-param name="sValue" select="substring-after($sValue, 'px')"/>
					</xsl:call-template>
				</xsl:variable>
				<xsl:value-of select="concat(substring($sBeforePx, 1, $nLengthBeforeInteger), string($nValueIn), 'in', $sRest)"/>
			</xsl:when>
			<xsl:otherwise>
				<xsl:value-of select="$sValue"/>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>
	<xsl:template name="altova:GetCharCountOfIntegerAtEndOfString">
		<xsl:param name="sText"/>
		<xsl:variable name="sLen" select="string-length($sText)"/>
		<xsl:variable name="cLast" select="substring($sText, $sLen)"/>
		<xsl:choose>
			<xsl:when test="number($cLast) &gt;= 0 and number($cLast) &lt;= 9">
				<xsl:variable name="nResultOfRest">
					<xsl:call-template name="altova:GetCharCountOfIntegerAtEndOfString">
						<xsl:with-param name="sText" select="substring($sText, 1, $sLen - 1)"/>
					</xsl:call-template>
				</xsl:variable>
				<xsl:value-of select="$nResultOfRest + 1"/>
			</xsl:when>
			<xsl:otherwise>
				<xsl:text>0</xsl:text>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>
	<xsl:template match="@* | node()" mode="altova:copy-table">
		<xsl:copy>
			<xsl:apply-templates select="@* | node()" mode="#current"/>
		</xsl:copy>
	</xsl:template>
	<xsl:template match="fo:table" mode="altova:copy-table">
		<xsl:choose>
			<xsl:when test="(empty(fo:table-body/fo:table-row) and empty(fo:table-header/fo:table-row) and empty(fo:table-footer/fo:table-row)) or empty(.//fo:table-cell)">				</xsl:when>
			<xsl:otherwise>
				<xsl:copy>
					<xsl:apply-templates select="@* | node()" mode="#current"/>
				</xsl:copy>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>
	<xsl:template match="fo:table-header | fo:table-footer" mode="altova:copy-table">
		<xsl:choose>
			<xsl:when test="empty(fo:table-row)">				</xsl:when>
			<xsl:otherwise>
				<xsl:copy-of select="."/>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>
	<xsl:template match="fo:table-body" mode="altova:copy-table">
		<xsl:choose>
			<xsl:when test="empty(fo:table-row)">
				<xsl:copy>
					<xsl:apply-templates select="@* | node()" mode="#current"/>
					<fo:table-row>
						<fo:table-cell>
							<fo:block/>
						</fo:table-cell>
					</fo:table-row>
				</xsl:copy>
			</xsl:when>
			<xsl:otherwise>
				<xsl:copy-of select="."/>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>
	<xsl:template match="fo:list-item[empty(@break-before)]" mode="second-step">
		<xsl:copy>
			<xsl:choose>
				<xsl:when test=".//altova:page-break">
					<xsl:attribute name="break-before" select="'page'"/>
				</xsl:when>
				<xsl:when test=".//altova:column-break">
					<xsl:attribute name="break-before" select="'column'"/>
				</xsl:when>
			</xsl:choose>
			<xsl:apply-templates select="@* | node()" mode="#current"/>
		</xsl:copy>
	</xsl:template>
	<xsl:template match="altova:pdf-bookmark-tree[@generate-from-toc = false()]" mode="second-step">
		<xsl:variable name="altova:pdf-bookmarks">
			<xsl:apply-templates mode="altova:filter-pdf-bookmark-tree"/>
		</xsl:variable>
		<xsl:if test="exists($altova:pdf-bookmarks/fo:bookmark)">
			<fo:bookmark-tree>
				<xsl:copy-of select="$altova:pdf-bookmarks"/>
			</fo:bookmark-tree>
		</xsl:if>
	</xsl:template>
	<xsl:template match="node()" mode="altova:filter-pdf-bookmark-tree">
		<xsl:apply-templates mode="#current"/>
	</xsl:template>
	<xsl:template match="altova:pdf-bookmark" mode="altova:filter-pdf-bookmark-tree">
		<fo:bookmark>
			<xsl:sequence select="@starting-state"/>
			<xsl:variable name="altova:hyperlink" select="altova:hyperlink[1]"/>
			<xsl:choose>
				<xsl:when test="not(exists($altova:hyperlink))">
					<xsl:message select="'Error: Found PDF bookmark without a corresponding hyperlink!'" terminate="yes"/>
					<xsl:attribute name="internal-destination" select="'undefined'"/>
					<fo:bookmark-title/>
				</xsl:when>
				<xsl:when test="not(starts-with($altova:hyperlink/@href,'#'))">
					<xsl:message select="concat('Error: External bookmark destinations (',$altova:hyperlink/@href,') are not supported by FOP 0.93/1.0!')" terminate="yes"/>
					<xsl:attribute name="internal-destination" select="'external-destination-not-supported'"/>
					<fo:bookmark-title>
						<xsl:sequence select="$altova:hyperlink//@color[1] | $altova:hyperlink//@font-style[.='normal' or .='italic'][1] | $altova:hyperlink//@font-weight[.='normal' or .='bold'][1]"/>
						<xsl:value-of select="string($altova:hyperlink)"/>
					</fo:bookmark-title>
				</xsl:when>
				<xsl:otherwise>
					<xsl:variable name="altova:bookmark-name" select="substring($altova:hyperlink/@href,2)"/>
					<xsl:variable name="altova:source-document" select="ancestor::*[self::altova:result-document | self::altova:main-document][1]"/>
					<xsl:variable name="altova:target-document" select="key('altova:bookmark-key',$altova:bookmark-name,$altova:design-xslt-tree-view)[1]/ancestor::*[self::altova:result-document | self::altova:main-document][1]"/>
					<xsl:choose>
						<xsl:when test="empty($altova:target-document) or $altova:source-document is $altova:target-document">
							<xsl:attribute name="internal-destination" select="$altova:bookmark-name"/>
						</xsl:when>
						<xsl:otherwise>
							<xsl:variable name="altova:relative-path" select="altova:calc-relative-path($altova:source-document/@url,$altova:target-document/@url)"/>
							<xsl:variable name="altova:url" select="concat(substring($altova:relative-path,1,string-length($altova:relative-path) - 3),'.pdf#dest=',$altova:bookmark-name)"/>
							<xsl:message select="concat('Warning: External bookmark destinations (',$altova:url,') are not supported by FOP 0.93/1.0!')"/>
							<xsl:attribute name="internal-destination" select="'external-destination-not-supported'"/>
						</xsl:otherwise>
					</xsl:choose>
					<fo:bookmark-title>
						<xsl:sequence select="$altova:hyperlink//@color[1] | $altova:hyperlink//@font-style[.='normal' or .='italic'][1] | $altova:hyperlink//@font-weight[.='normal' or .='bold'][1]"/>
						<xsl:value-of select="string($altova:hyperlink)"/>
					</fo:bookmark-title>
				</xsl:otherwise>
			</xsl:choose>
			<xsl:if test="count(altova:hyperlink) gt 1">
				<xsl:message select="concat('Error: Found PDF bookmark (',$altova:hyperlink/@href,') with more than one corresponding hyperlinks!')" terminate="yes"/>
			</xsl:if>
			<xsl:apply-templates mode="#current"/>
		</fo:bookmark>
	</xsl:template>
	<xsl:template match="fo:basic-link" mode="second-step">
		<xsl:choose>
			<xsl:when test="count(node()) eq 1 and fo:block">
				<fo:block>
					<xsl:apply-templates select="fo:block[1]/@*" mode="#current"/>
					<fo:basic-link>
						<xsl:apply-templates select="@*" mode="#current"/>
						<xsl:apply-templates select="fo:block[1]/node()" mode="#current"/>
					</fo:basic-link>
				</fo:block>
			</xsl:when>
			<xsl:otherwise>
				<xsl:copy>
					<xsl:apply-templates select="@* | node()" mode="#current"/>
				</xsl:copy>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>
	<xsl:function name="altova:is-node-empty" as="xs:boolean">
		<xsl:param name="altova:node" as="element()"/>
		<xsl:sequence select="every $altova:child in $altova:node/child::node() satisfies ( ( boolean( $altova:child/self::text() ) and string-length( $altova:child ) = 0 ) or ( ( boolean( $altova:child/self::altova:inline-container-substitute ) or boolean( $altova:child/self::fo:inline ) or boolean( $altova:child/self::fo:inline-container ) or boolean( $altova:child/self::fo:block ) or boolean( $altova:child/self::fo:basic-link ) ) and altova:is-node-empty( $altova:child ) ) )"/>
	</xsl:function>
	<xsl:template match="/">
		<xsl:apply-templates select="$altova:design-xslt-tree-view" mode="second-step"/>
	</xsl:template>
	<xsl:template match="altova:result-document" mode="second-step">
		<xsl:result-document href="{@url}">
			<xsl:apply-templates mode="#current"/>
		</xsl:result-document>
	</xsl:template>
	<xsl:template match="altova:bookmark" mode="second-step">
		<xsl:variable name="bookmark-content">
			<altova:bookmark>
				<xsl:apply-templates select="node()" mode="#current"/>
			</altova:bookmark>
		</xsl:variable>
		<xsl:choose>
			<xsl:when test="altova:is-node-empty($bookmark-content/altova:bookmark)">
				<fo:block>
					<xsl:apply-templates select="@*" mode="#current"/>
					<xsl:copy-of select="$bookmark-content/altova:bookmark/node()"/>
				</fo:block>
			</xsl:when>
			<xsl:otherwise>
				<fo:inline>
					<xsl:apply-templates select="@*" mode="#current"/>
					<xsl:copy-of select="$bookmark-content/altova:bookmark/node()"/>
				</fo:inline>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>
	<xsl:key name="altova:bookmark-key" match="altova:bookmark" use="@name"/>
	<xsl:template match="altova:bookmark/@name" mode="second-step">
		<xsl:attribute name="id" select="."/>
	</xsl:template>
	<xsl:template match="altova:hyperlink" mode="second-step">
		<fo:basic-link>
			<xsl:apply-templates select="@* | node()" mode="#current"/>
		</fo:basic-link>
	</xsl:template>
	<xsl:template match="altova:hyperlink/@href" mode="second-step">
		<xsl:choose>
			<xsl:when test="not(string(.))">
				<xsl:attribute name="external-destination" select="'url()'"/>
			</xsl:when>
			<xsl:when test="starts-with(.,'#')">
				<xsl:variable name="altova:bookmark-name" select="substring(.,2)"/>
				<xsl:variable name="altova:source-document" select="ancestor::*[self::altova:result-document | self::altova:main-document][1]"/>
				<xsl:variable name="altova:target-document" select="key('altova:bookmark-key',$altova:bookmark-name,$altova:design-xslt-tree-view)[1]/ancestor::*[self::altova:result-document | self::altova:main-document][1]"/>
				<xsl:choose>
					<xsl:when test="empty($altova:target-document) or $altova:source-document is $altova:target-document">
						<xsl:attribute name="internal-destination" select="$altova:bookmark-name"/>
					</xsl:when>
					<xsl:otherwise>
						<xsl:variable name="altova:relative-path" select="altova:calc-relative-path($altova:source-document/@url,$altova:target-document/@url)"/>
						<xsl:variable name="altova:url" select="concat(substring($altova:relative-path,1,string-length($altova:relative-path) - 3),'.pdf#dest=',$altova:bookmark-name)"/>
						<xsl:variable name="altova:escaped-url">
							<xsl:call-template name="altova:double-backslash">
								<xsl:with-param name="text" select="$altova:url"/>
								<xsl:with-param name="text-length" select="string-length($altova:url)"/>
							</xsl:call-template>
						</xsl:variable>
						<xsl:attribute name="external-destination" select="concat('url(',$altova:escaped-url,')')"/>
					</xsl:otherwise>
				</xsl:choose>
			</xsl:when>
			<xsl:otherwise>
				<xsl:variable name="altova:escaped-url">
					<xsl:choose>
						<xsl:when test="starts-with(.,'\\') or substring(.,2,1)=':'">
							<xsl:value-of select="iri-to-uri(concat('file:///',translate(.,'\','/')))"/>
						</xsl:when>
						<xsl:otherwise>
							<xsl:value-of select="iri-to-uri(.)"/>
						</xsl:otherwise>
					</xsl:choose>
				</xsl:variable>
				<xsl:attribute name="external-destination" select="concat('url(',$altova:escaped-url,')')"/>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>
	<xsl:template match="altova:inline-container-substitute" mode="second-step">
		<xsl:choose>
			<xsl:when test="altova:IsInline(.)">
				<fo:inline>
					<xsl:copy-of select="@* except @altova-DisableOutputEscaping"/>
					<xsl:apply-templates mode="second-step"/>
				</fo:inline>
			</xsl:when>
			<xsl:otherwise>
				<fo:block>
					<xsl:copy-of select="@* except @altova-DisableOutputEscaping"/>
					<xsl:apply-templates mode="second-step"/>
				</fo:block>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>
	<xsl:function name="altova:IsInline" as="xs:boolean">
		<xsl:param name="nodePassed" as="node()"/>
		<xsl:choose>
			<xsl:when test="(empty(for $i in $nodePassed/child::node() return index-of(('fo:block', 'fo:block-container', 'fo:list-block', 'fo:table'), name($i))) and (every $i in $nodePassed/altova:inline-container-substitute satisfies altova:IsInline($i))) or name($nodePassed/../..) eq 'fo:list-item-body'">
				<xsl:sequence select="true()"/>
			</xsl:when>
			<xsl:otherwise>
				<xsl:sequence select="false()"/>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:function>
	<xsl:template match="altova:main-document" mode="second-step">
		<xsl:apply-templates mode="#current"/>
	</xsl:template>
	<xsl:template match="altova:basic-link-container" mode="second-step">
		<fo:block text-align-last="justify">
			<xsl:apply-templates mode="second-step"/>
		</fo:block>
	</xsl:template>
	<xsl:template match="altova:page-break" mode="second-step">
		<xsl:if test="empty(ancestor::fo:list-item)">
			<fo:block break-after="page"/>
		</xsl:if>
	</xsl:template>
	<xsl:template match="altova:line-break" mode="second-step">
		<xsl:variable name="name-following-sibling" select="name(following-sibling::*[1])"/>
		<xsl:variable name="name-preceding-sibling" select="name(preceding-sibling::*[1])"/>
		<xsl:if test="($name-following-sibling and $name-following-sibling != 'fo:table' and $name-following-sibling != 'altova:line-break' and $name-preceding-sibling != 'altova:basic-link-container') or $name-preceding-sibling = 'altova:line-break'">
			<fo:block>
				<xsl:if test="($name-preceding-sibling != 'altova:inline-container-substitute' and $name-preceding-sibling != 'fo:inline' and $name-preceding-sibling != 'fo:basic-link' and $name-preceding-sibling != 'altova:bookmark' and $name-preceding-sibling != 'altova:hyperlink') or ($name-following-sibling != 'altova:inline-container-substitute' and $name-following-sibling != 'fo:inline' and $name-following-sibling != 'fo:basic-link' and $name-following-sibling != 'altova:bookmark' and $name-following-sibling != 'altova:hyperlink')">
					<fo:leader leader-pattern="space"/>
				</xsl:if>
			</fo:block>
		</xsl:if>
	</xsl:template>
	<xsl:template match="altova:column-break" mode="second-step">
		<xsl:if test="empty(ancestor::fo:list-item)">
			<fo:block break-after="column"/>
		</xsl:if>
	</xsl:template>
	<xsl:function name="altova:calc-relative-path" as="xs:string">
		<xsl:param name="altova:source-path"/>
		<xsl:param name="altova:target-path"/>
		<xsl:choose>
			<xsl:when test="$altova:source-path = $altova:target-path">
				<xsl:sequence select="''"/>
			</xsl:when>
			<xsl:when test="starts-with($altova:target-path,'http:') or starts-with($altova:target-path,'ftp:') or starts-with($altova:target-path,'file:')">
				<xsl:sequence select="$altova:target-path"/>
			</xsl:when>
			<xsl:otherwise>
				<xsl:variable name="altova:source-parts" select="tokenize($altova:source-path,'[/\\]')"/>
				<xsl:variable name="altova:target-parts" select="tokenize($altova:target-path,'[/\\]')"/>
				<xsl:variable name="altova:common-part-count" select="sum(for $i in (1 to count($altova:source-parts) - 1) return if( subsequence($altova:source-parts,1,$i) = subsequence($altova:target-parts,1,$i) ) then 1 else 0)"/>
				<xsl:sequence select="string-join((for $i in ($altova:common-part-count + 1 to count($altova:source-parts) - 1) return '..',for $i in ($altova:common-part-count + 1 to count($altova:target-parts)) return $altova:target-parts[$i]),'/')"/>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:function>
	<xsl:function name="altova:map-preview-filepath" as="xs:string">
		<xsl:param name="filepath"/>
		<xsl:sequence select="altovaext:create-temp-file-mapping($filepath)" use-when="function-available('altovaext:create-temp-file-mapping',1)"/>
		<xsl:sequence select="$filepath" use-when="not(function-available('altovaext:create-temp-file-mapping',1))"/>
	</xsl:function>
	<xsl:template match="*|@*|comment()|processing-instruction()" mode="second-step">
		<xsl:copy>
			<xsl:apply-templates select="node()|@* except @altova-DisableOutputEscaping" mode="second-step"/>
		</xsl:copy>
	</xsl:template>
	<xsl:template match="text()" mode="second-step">
		<xsl:choose>
			<xsl:when test="../@altova-DisableOutputEscaping">
				<xsl:value-of select="." disable-output-escaping="yes"/>
			</xsl:when>
			<xsl:otherwise>
				<xsl:copy/>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>
	<xsl:template match="altova:number" mode="second-step">
		<xsl:number level="single" count="altova:dummy-list-item | fo:list-item" format="{@format}" from="fo:list-block"/>
	</xsl:template>
	<xsl:template match="altova:dummy-list-item" mode="second-step">		</xsl:template>
	<xsl:function name="altova:AddRichEditStyles">
		<xsl:param name="altova:sStyleList" as="xs:string?"/>
		<xsl:variable name="altova:seqStyles" select="tokenize($altova:sStyleList, ';')" as="xs:string*"/>
		<xsl:for-each select="$altova:seqStyles">
			<xsl:variable name="altova:sStyleName" select="normalize-space(substring-before(., ':'))" as="xs:string?"/>
			<xsl:variable name="altova:sStyleValue" as="xs:string?">
				<xsl:call-template name="altova:MakeValueAbsoluteIfPixels">
					<xsl:with-param name="sValue" select="normalize-space(substring-after(., ':'))"/>
				</xsl:call-template>
			</xsl:variable>
			<xsl:if test="$altova:sStyleName and $altova:sStyleValue">
				<xsl:attribute name="{$altova:sStyleName}" select="$altova:sStyleValue"/>
			</xsl:if>
		</xsl:for-each>
	</xsl:function>
	<xsl:function name="altova:AddDynamicClassStyles">
		<xsl:param name="altova:sClassName" as="xs:string?"/>
		<xsl:variable name="nodeRule" select="$altova:nodeCssClasses/Class[@sSelector eq $altova:sClassName and ($altova:sCssSwitch eq '' or @sFile eq $altova:sCssSwitch)]" as="node()*"/>
		<xsl:if test="$nodeRule">
			<xsl:copy-of select="$nodeRule/Styles/@*"/>
		</xsl:if>
	</xsl:function>
	<xsl:function name="altova:GetChartYValuesForSingleSeries">
		<xsl:param name="seqCategoryLeafPos" as="node()*"/>
		<xsl:param name="nodeSeriesLeafPos" as="node()"/>
		<xsl:param name="bValuesInCategory" as="xs:boolean"/>
		<xsl:for-each select="$seqCategoryLeafPos">
			<xsl:element name="altova:Value">
				<xsl:value-of select="altova:GetChartYValueForSingleSeriesPos($nodeSeriesLeafPos, ., $bValuesInCategory)"/>
			</xsl:element>
		</xsl:for-each>
	</xsl:function>
	<xsl:function name="altova:GetChartYValueForSingleSeriesPos">
		<xsl:param name="nodeSeriesLeafPos" as="node()"/>
		<xsl:param name="nodeCategoryLeafPos" as="node()"/>
		<xsl:param name="bValuesInCategory" as="xs:boolean"/>
		<xsl:variable name="altova:seqCategoryContextIds" select="$nodeCategoryLeafPos/altova:Context/@altova:ContextId" as="xs:string*"/>
		<xsl:variable name="altova:seqSeriesContextIds" select="$nodeSeriesLeafPos/altova:Context/@altova:ContextId" as="xs:string*"/>
		<xsl:variable name="altova:sCommonContextId" select="for $i in $altova:seqCategoryContextIds return if (some $j in $altova:seqSeriesContextIds satisfies $i eq $j) then $i else ()" as="xs:string*"/>
		<xsl:choose>
			<xsl:when test="count($altova:sCommonContextId) gt 1">
				<xsl:message select="concat('XBRL Chart: Error: Found several values instead of a single one (contexts: ', string-join($altova:sCommonContextId, ', '), ').')" terminate="yes"/>
			</xsl:when>
			<xsl:when test="count($altova:sCommonContextId) lt 1">
				<xsl:message select="concat('XBRL Chart: Info: No value found for position labeled &quot;', $nodeCategoryLeafPos/@altova:sLabel, '&quot;')" terminate="no"/>
				<xsl:sequence select="'altova:no-value'"/>
			</xsl:when>
			<xsl:when test="$bValuesInCategory">
				<xsl:sequence select="xs:string($nodeCategoryLeafPos/altova:Context[@altova:ContextId eq $altova:sCommonContextId]/@altova:Value)"/>
			</xsl:when>
			<xsl:otherwise>
				<xsl:sequence select="xs:string($nodeSeriesLeafPos/altova:Context[@altova:ContextId eq $altova:sCommonContextId]/@altova:Value)"/>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:function>
	<xsl:function name="altova:GetChartLabelForPos" as="xs:string">
		<xsl:param name="nodeParam" as="node()"/>
		<xsl:value-of select="string-join($nodeParam/ancestor-or-self::altova:Pos/@altova:sLabel, ' ')"/>
	</xsl:function>
	<xsl:function name="altova:convert-length-to-pixel" as="xs:decimal">
		<xsl:param name="altova:length"/>
		<xsl:variable name="normLength" select="normalize-space($altova:length)"/>
		<xsl:choose>
			<xsl:when test="ends-with($normLength, 'px')">
				<xsl:value-of select="substring-before($normLength, 'px')"/>
			</xsl:when>
			<xsl:when test="ends-with($normLength, 'in')">
				<xsl:value-of select="xs:decimal(substring-before($normLength, 'in')) * $altova:nPxPerIn"/>
			</xsl:when>
			<xsl:when test="ends-with($normLength, 'cm')">
				<xsl:value-of select="xs:decimal(substring-before($normLength, 'cm')) * $altova:nPxPerIn div 2.54"/>
			</xsl:when>
			<xsl:when test="ends-with($normLength, 'mm')">
				<xsl:value-of select="xs:decimal(substring-before($normLength, 'mm')) * $altova:nPxPerIn div 25.4"/>
			</xsl:when>
			<xsl:when test="ends-with($normLength, 'pt')">
				<xsl:value-of select="xs:decimal(substring-before($normLength, 'pt')) * $altova:nPxPerIn div 72.0"/>
			</xsl:when>
			<xsl:when test="ends-with($normLength, 'pc')">
				<xsl:value-of select="xs:decimal(substring-before($normLength, 'pc')) * $altova:nPxPerIn div 6.0"/>
			</xsl:when>
			<xsl:otherwise>
				<xsl:value-of select="$normLength"/>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:function>
	<xsl:function name="altova:convert-length-to-mm" as="xs:decimal">
		<xsl:param name="altova:length"/>
		<xsl:variable name="normLength" select="normalize-space($altova:length)"/>
		<xsl:choose>
			<xsl:when test="ends-with($normLength, 'px')">
				<xsl:value-of select="xs:decimal(substring-before($normLength, 'px')) div $altova:nPxPerIn * 25.4"/>
			</xsl:when>
			<xsl:when test="ends-with($normLength, 'in')">
				<xsl:value-of select="xs:decimal(substring-before($normLength, 'in')) * 25.4"/>
			</xsl:when>
			<xsl:when test="ends-with($normLength, 'cm')">
				<xsl:value-of select="xs:decimal(substring-before($normLength, 'cm')) * 10"/>
			</xsl:when>
			<xsl:when test="ends-with($normLength, 'mm')">
				<xsl:value-of select="substring-before($normLength, 'mm') "/>
			</xsl:when>
			<xsl:when test="ends-with($normLength, 'pt')">
				<xsl:value-of select="xs:decimal(substring-before($normLength, 'pt')) * 25.4 div 72.0"/>
			</xsl:when>
			<xsl:when test="ends-with($normLength, 'pc')">
				<xsl:value-of select="xs:decimal(substring-before($normLength, 'pc')) * 25.4 div 6.0"/>
			</xsl:when>
			<xsl:otherwise>
				<xsl:value-of select="number($normLength) div $altova:nPxPerIn * 25.4"/>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:function>
</xsl:stylesheet>
